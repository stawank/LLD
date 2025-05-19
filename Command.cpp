#include<iostream>

using namespace std;
#include <vector>

/*
Command Design pattern: 

Actions to be performed -> When a trigger (invoke) happens
* Examples:
- Placing an order (Uber)
- Creating Invoice (Uber)
- Request a ride (Uber)

- Copy Text (Editor)
- Paste Text  (Editor)


* On code level, treat every command as an Object. -> Encapsulate command as Object
* Consider the loose coupling between command and action to be perform

* Component 1: Command Interface
    - Abtract Method
        - execute()

* Component 2: Concrete Command  Objects (implements Command Interface)
    - Implementation of execute()

* Component 3: Invoker
    - Uses concrete command objects (aggreagation or association with commands -> Depends)  

* Component 4: Reciever
    - Action is performed by reciever


*/

class ICommand{
    /* Command interface */
    public:
    virtual void execute() = 0;


};
class Document{
    /* Reciever */
    public:
    void Open(){
        cout<< "Opening Document" << endl;
    }

    void Close(){
    cout<< "Closing Document" << endl;
    }
};

class Open: public ICommand {
    /* Concrete Command */
    private:
    Document* doc;

    public:
    Open(Document* doc): doc(doc) {} 
    void execute() {
        doc->Open();
    }

};

class Close: public ICommand {
    /* Concrete Command */
    private:
    Document* doc;

    public:
    Close(Document* doc): doc(doc) {} 
    void execute() {
        doc->Close();
    }

};

class Menu {

    vector<ICommand*> commandlist;

    public:

    void addCommand(ICommand* command){
        commandlist.push_back(command);
    }


    void executeCommands(){
        for (int i = 0; i<commandlist.size(); i++){
            commandlist[i]->execute();
        }
    }




};














int main(){
    Document* doc = new Document();
    Menu* menu = new Menu();
    ICommand* command1 = new Open(doc);
    ICommand* command2 = new Close(doc);

    menu->addCommand(command1);
    menu->addCommand(command2);

    menu->executeCommands();





    return 0;
}