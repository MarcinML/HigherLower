#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

int pickRandomNumber()
{
    int random =( std::rand() % 101 ) + 1;
    return random;
}

int main()
{
srand(time(NULL));
char quit=0;
int chances;
int answer=0;
bool succes{};

std::cout<<"Welcome to Higher/Lower game!\nRules are simple:\n-You have 7 chances to guess the number (1-100) program picked up"<<std::endl;
int secretNumber;


do
{
    std::cout<<"I'm ready, Guess the secret number"<<std::endl;
    secretNumber = pickRandomNumber();
    chances = 7;

    while(chances!=0)
    {
       do
        {
            std::cin>>answer;
            succes=std::cin.fail();
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n');
        } while(succes);

        if(answer == secretNumber)
        {
            std::cout<<"You won!!!!!\n";
            break;
        }
        if(answer != secretNumber)
        {
           chances--;
           if(chances==0)
           {
               std::cout<<"You loose"<<" You have "<<chances<< " more chances\n";
               break;
           }
           std::cout<<"Try one more time"<<" You have "<<chances<< " more chances\n";
           if(answer>secretNumber) std::cout<<"Secret number is LESS than your answer"<<std::endl;
           if(answer<secretNumber) std::cout<<"Secret number is GREATER than your answer"<<std::endl;
         }
    }
    std::cout<<"Secret number was "<< secretNumber << "\nWanna play again? (y/n): "<<std::endl;
    std::cin>>quit;

}while(quit == 'y' || quit == 'Y');

    return 0;
}
