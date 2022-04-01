#include "clienti.h"

using namespace std;

void Print()
{
    printf("For calling an instruction you have to specify it and then on the next line you have to introduce the input data\n");
    printf("List of instructions:\n");
    printf("Add client <id> <name> <cnp> <telephone_number> <subscription name> <price of subscription> <period> <discount (if existst)>\n");
    printf("Add <number of clients> - then introduce client's info as above on separate lines\n");
    printf("Show client <client's index >\n");
    printf("Delete client <client's index>\n");
    printf("Delete all clients\n");
    printf("Print number of premium clients\n");
    printf("Print income\n");
    printf("Exit\n");
}

void Run_Instruction(Clienti clients_object, char str[])
{
    const char DELIMITER[]="\n<------------------------------------------>\n";
    char *pointer;
    pointer = strtok(str, " ");
    if(pointer == NULL)
        return;
    if(strcmp(pointer, "Exit"))
        exit(0);
    else
    {
        if(strcmp(pointer, "Show"))
            return;
    }
}

void Run()
{
    char s[1005];
    Print();
    Clienti clients_object;
    while(true)
    {
        cin.getline(s, 1000);
        Run_Instruction(clients_object, s);
    }
}

int main()
{
    // Clienti a;
    // a.addClient(123, "misu", "213", "05552", "troleu", 132.2, 2);
    // a.addClient(1233, "andrei", "23", "0555204787", "metrou", 12.2, 2, 2);
    // a.ShowClient(1);
    // cout << '\n';
    // a.ShowClient(2);
    // cout << '\n' << a.GetNrAbonatiPremium() << ' ' << a.Suma() << '\n';
    // a.ShowClientSubs(1); cout << '\n'; a.ShowClientSubs(2);
    return 0;
}