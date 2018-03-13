#include <iostream>
#include <ctime>
#include <cstdlib>

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

std::cout<<"Welcome to Higher/Lower game!\nRules are simple:\n-You have 7 chances to guess the number (1-100) program picked up"<<std::endl;
int secretNumber;


do
{
    std::cout<<"I'm ready, Guess the secret number"<<std::endl;
    secretNumber = pickRandomNumber();
    chances = 7;
    while(chances!=0)
    {
        std::cin>>answer;
        if(answer == secretNumber)
        {
            std::cout<<"You won!!!!!\n";
            break;
        }
        if(answer != secretNumber)
        {
            chances--;
            if(chances==0) break;
           std::cout<<"Try one more time"<<" You have "<<chances<< " more chances\n";
           if(answer>secretNumber) std::cout<<"Secret number is less than your answer"<<std::endl;
           if(answer<secretNumber) std::cout<<"Secret number is greater than your answer"<<std::endl;

        }
    }

    std::cout<<"Secret number was "<< secretNumber << "\nWanna play again? (y/n): "<<std::endl;
    std::cin>>quit;

}while(quit == 'y' || quit == 'Y');




    return 0;
}
