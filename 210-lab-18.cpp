//COMSC-210 | Lab 18 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declaring the Node struct so that we can generate a linked list
struct Node {
    float value;
    string comments;
    Node *next;
};

//prototype functions that add the values to either end of the linked list, output the list itself, and delete the list
void addToHead(float val, string com, Node *&hd);
void addToTail(float val, string com, Node *&hd);
void output(float val, int c, Node * hd);
void deleteList(Node *hd);

int main()
{
    //declaring and initializing the variables we will be using throughout the program
    Node *head = nullptr;
    int count = 0;
    float reviewScore;
    float totalScore;
    string reviewNotes;
    char response;
    int insertion;

    //asks the user if they would like to add the nodes to the head or the tail of the linked list
    cout << "Which linked list method should we use?\n";
        cout << setw(15) << "[1] New nodes are added at the head of the linked list\n";
        cout << setw(15) << "[2] New nodes are added at the tail of the linked list\n";
        cin >> insertion;
        cin.ignore();

    //asks if the user wishes to enter a review of a movie
    cout << "Enter a review? Y/N ";
    cin >> response;
    cin.ignore();

    while (true)
    {
         //asks the user whether they would like to insert the previously obtained random value at the head or the tail end of the linked list
        if(response == 'Y' || response == 'y')
        {
           count++;
            //prompts the user to enter a review score
            cout << "Enter review rating 0-5: ";
            cin >> reviewScore;
            cin.ignore();

            //adds this review score to the total score
            totalScore += reviewScore;
            
            //prompts the user to enter a comment about the movie
            cout << "Enter review comments: ";
            getline(cin, reviewNotes);

            //determines, which function will be called to either add the value found to the front or back of the linked list respectively
            if(insertion == 1)
                addToHead(reviewScore, reviewNotes, head);
            else if(insertion == 2)
                addToTail(reviewScore, reviewNotes, head);
        }
        
        //asks the user if they would like to enter another review
        cout << "Enter another review? Y/N: ";
        cin >> response;
        cin.ignore();

        //if they respond no then the loop breaks, but if they input a response that is neither yes or no then the loop will output an invalid response message
        if (response == 'n' || response == 'N') break;
        else if(response != 'Y' && response != 'y' && response != 'n' && response != 'N')
            cout << "Invalid response. Please try again.\n"; 
    }
    
    //calls the output function to display the information gathered in this program
    output(totalScore, count, head);

    //calls the delete function to delete the linked list and clear memory
    deleteList(head);

    return 0;
}

//function to display the information gathered
void output( float val, int c, Node * hd) 
{
    //if there is nothing on the linked list, then an empty list message is displayed
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;

    cout << "Outputting all reviews:\n";

    //while loop that traverses the linked list and outputs the review score and the review comments
    while (current) 
    {
        cout << setw(15) << "> Review #" << count++ << ": " << current->value << ": " << current->comments << endl;
        current = current->next;
    }

    //calculates the average review score that was inputted into the program
    float average = val / c;
    cout << setw(24) << "> Average Rating : " << average << endl;
}

//function that adds the values to the head of the linked list
void addToHead(float val, string com, Node *&hd)
{
    Node *newVal = new Node;
        
    // if this is the first node, it's the new head
        if (!hd) 
        { 
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = val;
            newVal->comments = com;
        }
        // if its a second or subsequent node; place at the head
        else 
        {
            newVal->next = hd;
            newVal->value = val;
            newVal->comments = com;
            hd = newVal;
        }
}

//function that adds the values to the tail end of the linked list
void addToTail(float val, string com, Node *&hd)
{
     Node *newVal = new Node;
    // adds node at head if list is empty, as that position would also technically be the tail end
    if (hd == nullptr) 
    {
        hd = newVal;
        newVal->next = nullptr;
        newVal->value = val;
        newVal->comments = com;
    }
    //iff the list is not empty, the function will traverse the array until it reaches the last value, at which point it will add the designated value to the end of the list
    else if (hd != nullptr)
    {
        Node *current = hd;
        while(current->next != nullptr)
            {
            current = current->next;
            }
        current->next = newVal;
        newVal->next = nullptr;
        newVal->value = val;
        newVal->comments = com;
    }
}

//function that deletes the linked list
void deleteList(Node *hd)
{
    Node *current = hd;
    while (current) 
    {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}