//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Avoid coupling the sender of a request to its receiver by giving more than one object
//a chance to handle the request.
//
//Chain the receiving objects and pass the request along the chain until an object
//handles it.
#pragma once


namespace chain
{

	class Request
	{
	private:
		int _data;

	public:
		const int getTarget();
		Request(int data);
	};
	// "Handler" 
	class Handler
	{
	protected:
		virtual bool CanHandle(Request*) = 0;
		Handler *successor;
	public:
		static void Test();
		void SetSuccessor(Handler *successor);

		virtual void HandleRequest(Request*) = 0;
	};

	// "ConcreteHandlerA" 
	class ConcreteHandlerA : public Handler
	{
	protected:
		virtual bool CanHandle(Request*);
	public:
		virtual void HandleRequest(Request *request);
	};

	// "ConcreteHandlerB" 
	class ConcreteHandlerB : public Handler
	{
	protected:
		virtual bool CanHandle(Request*);
	public:
		virtual void HandleRequest(Request *request);
	};

	// "ConcreteHandlerC" 
	class ConcreteHandlerC : public Handler
	{
	protected:
		virtual bool CanHandle(Request*);
	public:
		virtual void HandleRequest(Request *request);
	};

}
