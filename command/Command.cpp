//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Command: //Encapsulate a request as an object, thereby letting you parameterize clients with
//different requests, queue or log requests, and supports undoable operations.
#include "stdafx.h"
#include "command.h"
namespace command
{

	void CommandClient::Test()
	{
	
		// Initializers
		Receiver *receiver = new Receiver();
		// Create historicInvoker 
		Invoker *historicInvoker = new Invoker();
	
		// Create do and undo Command operation and execute the former
		historicInvoker->Action(new ConcreteCommand(receiver, "+", "100"), new ConcreteCommand(receiver,  "-","100"));//
		historicInvoker->Action(new ConcreteCommand(receiver, "-", "50"), new ConcreteCommand(receiver,  "+","50"));//
		historicInvoker->Action(new ConcreteCommand(receiver, "*", "10"), new ConcreteCommand(receiver, "/", "10"));//
		historicInvoker->Action(new ConcreteCommand(receiver, "/", "2"), new ConcreteCommand(receiver,  "*","2"));//
	
		// Undo all commands
		int histLen = historicInvoker->size();
		std::cout << "undoing " << histLen << std::endl;
		historicInvoker->Undo(histLen);
	
		// Redo some commands
		histLen--;
		std::cout << "redoing " << histLen << std::endl;
		historicInvoker->Redo(histLen);
		historicInvoker->Clear();
	}
 #pragma warning( push )
 #pragma warning( disable:  4996 4018)
	ConcreteCommand::ConcreteCommand(Receiver *receiver,...)
	{
	
		this->_receiver = receiver;
		/*


		  // if ( i != 0 ) {
			  int n = va_arg( argptr, int );
			  printf( "%d\n", n );
*/
		_args = new char*[2];
		_args[0] = new char[2];
		_args[1] = new char[50];
		va_list argptr; 
		va_start(argptr, receiver);   //Initialize variable arguments. 	
		char* tmp= va_arg( argptr, char*);
		::strcpy(_args[0], tmp );
		tmp= va_arg( argptr, char*);
		::strcpy(_args[1], tmp);
	    va_end( argptr ); 
	}

	bool ConcreteCommand::Execute()
	{
	
		_receiver->Action(_args);
		//based on _args values add (return true) or not (return false) to Invoker's history
		return true;

	}
	ConcreteCommand::~ConcreteCommand()
	{
			delete _args[0];
			delete _args[1];
			delete _args;
	}
	void Receiver::Action(char** args)
	{
		std::cout << "Action in Receiver got the parameters: ";
		std::cout <<   args[0]<< '\t' << args[1] << "\r\n";
		// here the Receiver does the concrete operation
	}

	Cmds::Cmds(Command *doCmd, Command *undoCmd)
	{
		DoCmd = doCmd;
		UnDoCmd = undoCmd;
	}

	int Invoker::getHistoryLenght()
	{
		return this->size();
	}

	int Invoker::Redo(int levels)
	{
		std::cout << "Redo " << levels << std::endl;
		// Perform redo operations
		for (int i = 0; i < levels; i++)
		{
			if (_current < this->size() - 1)
			{
				Command *command = (*this)[_current]->DoCmd;
				
				if (command->Execute())
					_current++;
				else
					return i; //stop redoing when fails
	
			}
			else
				return i;
		}
		return levels;
	}

	int Invoker::Undo(int levels)
	{
		std::cout << "---- Undo " << levels << std::endl;
		// Perform undo operations
		for (int i = 0; i < levels; i++)
		{
			if (_current > 0)
			{
				--_current;
				Command *command = (*this)[_current]->UnDoCmd;
				if (!command->Execute())
					return i; //stop undoing when fails
			}
			else
				return i;
		}
		return levels;
	}
	void Invoker::Clear()
	{
		  for (std::vector<Cmds*>::iterator it = this->begin() ; it != this->end(); ++it)
		  {
			  if(*it && (*it)->DoCmd)
				delete (*it)->DoCmd;
			  if(*it && (*it)->UnDoCmd)
				delete (*it)->UnDoCmd;
		  }
		  this->clear();

	}
	bool Invoker::Action(Command *doCommand, Command *undoCommand)
	{
		if (doCommand->Execute())
		{
			// Add Commands to history if not failed or flagged
			this->push_back(new Cmds(doCommand, undoCommand));
			_current++;
			return true;
		}
		else
			return false;
	
	}
}
#pragma warning( pop )