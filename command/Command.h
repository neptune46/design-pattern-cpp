//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Command: //Encapsulate a request as an object, thereby letting you parameterize clients with
//different requests, queue or log requests, and supports undoable operations.
#pragma once
#include <vector>
#include <iostream>
#include <stdarg.h>

//command design pattern with do/undo history
namespace command
{

	/// <summary>
	/// Client startup class for do/undo history 
	/// </summary>
	class CommandClient
	{
		/// <summary>
		/// just for testing
		/// </summary>
	public:
		static void Test();

	};



	/// <summary>
	/// The 'Command' abstract class
	/// </summary>
	class Command
	{
	public:
		virtual bool Execute() = 0;
		virtual ~Command(){}//allows for calling ~ConcreteCommand()
	};



	/// <summary>
	/// The Receiver class
	/// </summary>
	class Receiver
	{
	public:
		void Action(char** args);
	};

	/// <summary>
	/// The 'ConcreteCommand' class
	/// </summary>
	class ConcreteCommand : public Command
	{

	private:
		Receiver *_receiver;
		char** _args;

		// Constructor
	public:
		ConcreteCommand(Receiver *receiver, ...);

		// Concrete execution by Receiver
		virtual bool Execute();
		virtual ~ConcreteCommand();

	};

	class Cmds
	{
	public:
		Cmds(Command *doCmd, Command *undoCmd);
		Command *DoCmd;
		Command *UnDoCmd;
	};

	/// <summary>
	/// The 'Invoker' class
	/// </summary>
	class Invoker : public std::vector<Cmds*>
	{
	public:

		// Initializers
	private:
		int _current;

	public:
		int getHistoryLenght();
		int Redo(int levels);

		void Clear();
		int Undo(int levels);

		bool Action(Command *doCommand, Command *undoCommand);
	};
}
