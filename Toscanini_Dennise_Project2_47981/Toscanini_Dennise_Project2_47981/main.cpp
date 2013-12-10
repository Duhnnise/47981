/*
    Dennise Toscanini
    November 25, 2013
    Project 1 V2
*/

//Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//No Global Constants

//Function Prototypes
//function return true if all the elements in bool array are true
bool gueswrd(bool gotlett[], string theWord);

//function shows the hangman's current state
void hangman(int num_try);

//Execution Begins Here
int main(){
    char again;//declare again above do while loop in order to enable user to play multiple times
do{     
     srand(time(NULL));
    //Declare Stream
    ifstream in_stream;
    //Declare Variables
    string words[11];
    int number = rand() % 11, num_try = 0;//will randomly pick a word from text document
    int count = 0;//counts words in text document   
    
    in_stream.open("hangman.txt");//open text file containing words to be guessed
    
    if(in_stream.fail()){//in case text document cant be read program will close
         cout << "\aFile open procedure failed";
         cout << "\nPlease make sure the file exists in the root directory before proceeding";
         cout << "\nPress any key to continue. . .";
         cin.get();
         return 0;    
    }
    
    in_stream.clear();//resets text marker back to the beginning of document
    
   	while(in_stream >> words[count])//while there is a number in file that can be put into the variable words[count] then increment the count
	{
        count++;
	}    
 	string theWord(words[number]); 
    char blank = '_', space = ' ', guess;

    const int maxtry = 6;//indicates the max number of guesses the user gets
    
    //gotlett defines how many characters are in the string
    bool gotlett[theWord.length()], found = false;//define bool found to always be false

    cout << "\t***WELCOME TO HANGMAN***" << endl;
    cout << "Are you ready to play?" << endl;
    
    for(int i = 0; i < theWord.length(); i++){//show blanks
        cout << blank << ' ';
        gotlett[i] = false;
    }

    do{
    //user enters guess
        cout << endl;
        cout << endl;
        cout << "Enter a letter " << endl;
        cout << "Your Guess: ";
        cin >> guess;
        found = false;

        for(int i = 0; i < theWord.length(); i++){//if letter guess is in theWord return true
            if(guess == theWord[i]){
                gotlett[i] = true;
                found = true;
            }
        }

        if(found == false){//else return false
            num_try++;//increment number of tries
        }

        for(int i = 0; i < theWord.length(); i++){//Display letters that have been guess correctly
            if(gotlett[i] == true){
                cout << theWord[i] << ' ';
            }

            else{//replace all letters that have not been guessed with a blank
                cout << blank << space;
            }
        }

        cout << endl;

        hangman(num_try);//call on the proper switch statement to show hangmans body
     
     //call function gueswrd    
     //do all of the above so long as the word has not been guessed and
     //the number of maxtry has not been exceeded
    }while((gueswrd(gotlett, theWord) == false) && (num_try < maxtry));

        //if bool gueswrd returns true user wins
        if(gueswrd(gotlett, theWord) == true){
        cout << endl;
        cout << "YOU WIN!" << endl;
    }

    else{//if bool gueswrd returns false and maxtry has been exceeded
        cout << endl;
        cout << "YOU LOSE!" << endl;
    }

    //Exit Stage Right
    cout << endl;
    cout << "Would you like to try again? " << endl;
    cout << "Type Y for yes" << endl;
    cin >> again;
    
//allow user to play as many times as desired   
}while (again == 'Y' || again == 'y');
    //Exit Stage Right
    return 0;
}

bool gueswrd(bool gotlett[], string theWord){
    for(int i = 0; i < theWord.length(); i++){
        if(gotlett[i] == false){
            return false;//if all letters have not been guessed return false
        }
    }

    return true;//if all letters have been guessed return true
}

void hangman(int num_try){
    //hangman body segments
    char guy1[3][3]= {{' ', 'O', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}};

    char guy2[3][3]= {{' ', 'O', ' '},
                      {' ', 'x', ' '},
                      {' ', ' ', ' '}};

    char guy3[3][3]= {{' ', 'O', '/'},
                      {' ', 'x', ' '},
                      {' ', ' ', ' '}};

    char guy4[3][3]= {{' ',  'O', '/'},
                      {' ',  'x', ' '},
                      {' ',  ' ', '\\'}};

    char guy5[3][3]= {{'\\', 'O', '/'},
                      {' ',  'x', ' '},
                      {' ',  ' ', '\\'}};

    char guy6[3][3]= {{'\\', 'O', '/'},
                      {' ',  'x', ' '},
                      {'/',  ' ', '\\'}};

    cout << endl;
    cout << "\t***" << endl;

    switch(num_try){
        //While guesses are under max tries
        //no wrong guesses have been made
        case 0:{
            cout << "No misses yet, good job" << endl;

            break;
        }
        //first wrong guess
        case 1:{

            if(num_try == 1){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout<< guy1[i][j];
                    }

                    cout << endl;
                }
            }
            break;
        }
        //second wrong guess
        case 2:{

            if(num_try == 2){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout<< guy2[i][j];
                    }

                    cout << endl;
                }
            }

            break;
        }
        //third wrong guess
        case 3:{

            if(num_try == 3){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout<< guy3[i][j];
                    }

                    cout << endl;
                }
            }

            break;
        }
        //fourth wrong guess
        case 4:{

            if(num_try == 4){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout<< guy4[i][j];
                    }

                    cout << endl;
                }
            }

            break;
        }
        //fifth wrong guess
        case 5:{

            if(num_try == 5){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout<< guy5[i][j];
                    }

                    cout << endl;
                }
            }

            break;
        }
        //sixth wrong guess
        case 6:{

            if(num_try == 6){
                for (int i=0; i<3; i++){
                    cout << "\t";

                    for(int j=0; j<3; j++){
                        cout << guy6[i][j];
                    }

                    cout << endl;
                }
            }

            break;
        }
        //in case none of the above conditions above have been met
        default:{
            cout << "\nUnable to process\n";
            break;
        }
    }

    cout << endl;
    cout << "\t***" << endl;

    return;
}
