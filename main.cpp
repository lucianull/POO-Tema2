#include "clienti.h"

using namespace std;

void Print()
{
    printf("For calling an instruction you have to specify it and then on the next line you have to introduce the input data\n");
    printf("List of instructions:\n");
    printf("Add client <id> <name> <cnp> <telephone_number> <subscription name> <price of subscription> <period> <discount (if existst)>\n"); //
    printf("Add <number of clients> - then introduce client's info as above on separate lines\n"); //
    printf("Show client <client's index >\n"); //
    printf("Show all clients\n");
    printf("Delete client <client's index>\n"); //
    printf("Delete all clients\n"); //
    printf("Print the number of clients\n");
    printf("Print the number of premium clients\n");
    printf("Print the number of normal clients\n");
    printf("Print income\n");
    printf("Exit\n"); //
}

void ShowClient(Clienti &clients_object, int clientIndex)
{
    clients_object.ShowClient(clientIndex);
    cout << ' ';
    clients_object.ShowClientSubs(clientIndex);
    cout << '\n';
}

void AddObject(Clienti &clients_object, char* pointer)
{
    int id, perioada;
    float reducere, pret;
    string nume, cnp, nr_telefon, nume_abonament;
    id = atoi(pointer);
    pointer = strtok(NULL, " ");
    nume = pointer;
    pointer = strtok(NULL, " ");
    cnp = pointer;
    pointer = strtok(NULL, " ");
    nr_telefon = pointer;
    pointer = strtok(NULL, " ");
    nume_abonament = pointer;
    pointer = strtok(NULL, " ");
    pret = atof(pointer);
    pointer = strtok(NULL, " ");
    perioada = atoi(pointer);
    pointer = strtok(NULL, " ");
    if(pointer)
    {
        reducere = atof(pointer);
        clients_object.addClient(id, nume, cnp, nr_telefon, nume_abonament, pret, perioada, reducere);
    }
    else
        clients_object.addClient(id, nume, cnp, nr_telefon, nume_abonament, pret, perioada);
}

void AddNObjects(Clienti &clients_object, int n)
{
    char str[1001], *pointer;
    for(int i = 1; i <= n; i++)
    {
        cin.getline(str, 1000);
        pointer = strtok(str, " ");
        AddObject(clients_object, pointer);
    }
}

void DeleteAll(Clienti &clients_object)
{
    while(int size = clients_object.size())
        clients_object.popClient(size);
}

void DeleteClient(Clienti &clients_object, int clientIndex)
{
    clients_object.popClient(clientIndex);
}

void ShowAllClients(Clienti &clients_object)
{
    int size = clients_object.size();
    for(int i = 1; i <= size; i++)
        ShowClient(clients_object, i);
}

void Run_Instruction(Clienti &clients_object, char str[])
{
    const char DELIMITER[]="\n<------------------------------------------>\n";
    char *pointer;
    pointer = strtok(str, " ");
    if(pointer == NULL)
        return;
    if(!strcmp(pointer, "Exit"))
        exit(0);
    else
    {
        if(!strcmp(pointer, "Show"))
        {
            pointer = strtok(NULL, " ");
            if(!strcmp("all", pointer))
                ShowAllClients(clients_object);
            else
            {
                pointer = strtok(NULL, " ");
                ShowClient(clients_object, atoi(pointer));
            }

        }
        else
        {
            if(!strcmp(pointer, "Add"))
            {
                pointer = strtok(NULL, " ");
                if(isdigit(pointer[0]))
                    AddNObjects(clients_object, atoi(pointer));
                else
                    {
                        pointer = strtok(NULL, " ");
                        AddObject(clients_object, pointer);
                    }
            }
            else
            {
                if(!strcmp("Delete", pointer))
                {
                    pointer = strtok(NULL, " ");
                    if(!strcmp("all", pointer))
                        DeleteAll(clients_object);
                    else
                        pointer = strtok(NULL, " "), DeleteClient(clients_object, atoi(pointer));
                }
                else
                {
                    pointer = strtok(NULL, " ");
                    if(!strcmp(pointer, "income"))
                        cout << clients_object.Suma();
                    else
                    {
                        pointer = strtok(NULL, " "); pointer = strtok(NULL, " "); pointer = strtok(NULL, " ");
                        if(!strcmp("clients", pointer))
                            cout << clients_object.size() << '\n';
                        else
                        {
                            if(!strcmp("premium", pointer))
                                cout << clients_object.GetNrAbonatiPremium() << '\n';
                            else
                                cout << clients_object.size() - clients_object.GetNrAbonatiPremium() << '\n';
                        }
                    }
                }
            }
        }

    }
    printf("%s", DELIMITER);
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
     Run();
    return 0;
}
