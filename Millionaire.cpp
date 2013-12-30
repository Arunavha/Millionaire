#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>

//QUESTIONS
struct quest
{
int qno, fopt[2];
char q[150], opt[4][30], copt, popt;
long valwon, valq, valsaf;
} qtn[16];
long amt;

void ask(int x);
void test(int x);
void f50(int x);
void audi(int x);



//COUNTERS
int ffct=0, apct=0, pg=1;

void assign(quest qtn[16])
{
//ASSIGN SAFE HAVENS
int a=0;
for(a=0;a<15;a++)
{
qtn[a].qno=a+1;
if(a>=0 && a<=3)
{qtn[a].valsaf=0;}
if(a>=4 && a<=7)
{qtn[a].valsaf=4000;}
if(a>=8)
{qtn[a].valsaf=64000;}
}

//ASSIGN Q VALUES
qtn[0].valq=500;
qtn[1].valq=1000;
qtn[2].valq=2000;
qtn[3].valq=4000;
qtn[4].valq=8000;
qtn[5].valq=16000;
qtn[6].valq=32000;
qtn[7].valq=64000;
qtn[8].valq=125000;
qtn[9].valq=250000;
qtn[10].valq=500000;
qtn[11].valq=1000000;
qtn[12].valq=3000000;
qtn[13].valq=5000000;
qtn[14].valq=7000000;

//ASSIGN VALUES WON
qtn[0].valwon=0;
for(int b=1;b<=15;b++)
{
 qtn[b].valwon=qtn[b-1].valq;
}

//THE QUESTIONS LIST
strcpy(qtn[0].q, "To exact revenge is also called taking a ____ for a ____");
strcpy(qtn[1].q, "Who is the current President of United States of America?");
strcpy(qtn[2].q, "Which Zodiac Sign is represented by a lion?");
strcpy(qtn[3].q, "Who is called the father of computers?");
strcpy(qtn[4].q, "The KIWI is indigenous to which country?");
strcpy(qtn[5].q, "Albert Einstein won the Nobel Prize in 1921 in which field?");
strcpy(qtn[6].q, "Who is credited as the inventor of the World Wide Web?");
strcpy(qtn[7].q, "Which country lies in two continents?");
strcpy(qtn[8].q, "Which country has the most Summer Olympic Gold Medals in history with 976 medals?");
strcpy(qtn[9].q, "Who was the only person to win both an Oscar and a Nobel Prize?");
strcpy(qtn[10].q, "Established in 1088 AD, which is the oldest university in the world?");
strcpy(qtn[11].q, "The coldest natural temperature ever recorded on Earth was -89.2 Celsius. What was the name of the place?");
strcpy(qtn[12].q, "In Nazi Germany, after Hitler died, a person succeeded him as Chancellor of Germany and was in office for only 1 day. Who was this?");
strcpy(qtn[13].q, "Sir Arthur Conan Doyle used to play football as a goalkeeper under the pseudonym, AC Smith. For which club did he play?");
strcpy(qtn[14].q, "Krishna Bhanji is the real name of which famous personality?");

//THE OPTIONS LIST
strcpy(qtn[0].opt[0], "Eye");
strcpy(qtn[0].opt[1], "Ear");
strcpy(qtn[0].opt[2], "Mouth");
strcpy(qtn[0].opt[3], "Nose");

strcpy(qtn[1].opt[0], "Mitt Romney");
strcpy(qtn[1].opt[1], "Hilary Clinton");
strcpy(qtn[1].opt[2], "Barack Obama");
strcpy(qtn[1].opt[3], "Chuck Norris");

strcpy(qtn[2].opt[0], "Libra");
strcpy(qtn[2].opt[1], "Leo");
strcpy(qtn[2].opt[2], "Cancer");
strcpy(qtn[2].opt[3], "Virgo");

strcpy(qtn[3].opt[0], "Bill Gates");
strcpy(qtn[3].opt[1], "John Napier");
strcpy(qtn[3].opt[2], "Steve Jobs");
strcpy(qtn[3].opt[3], "Charles Babbage");

strcpy(qtn[4].opt[0], "France");
strcpy(qtn[4].opt[1], "New Zealand");
strcpy(qtn[4].opt[2], "Russia");
strcpy(qtn[4].opt[3], "Tanzania");

strcpy(qtn[5].opt[0], "Physics");
strcpy(qtn[5].opt[1], "Chemistry");
strcpy(qtn[5].opt[2], "Peace");
strcpy(qtn[5].opt[3], "Mathematics");

strcpy(qtn[6].opt[0], "Sergei Brins");
strcpy(qtn[6].opt[1], "Larry Ellison");
strcpy(qtn[6].opt[2], "Tim Berners-Lee");
strcpy(qtn[6].opt[3], "Jeff Bezos");

strcpy(qtn[7].opt[0], "Cyprus");
strcpy(qtn[7].opt[1], "Turkey");
strcpy(qtn[7].opt[2], "American Samoa");
strcpy(qtn[7].opt[3], "Greenland");

strcpy(qtn[8].opt[0], "United States of America");
strcpy(qtn[8].opt[1], "Great Britain");
strcpy(qtn[8].opt[2], "China");
strcpy(qtn[8].opt[3], "Russia");

strcpy(qtn[9].opt[0], "Al Gore");
strcpy(qtn[9].opt[1], "George Bernard Shaw");
strcpy(qtn[9].opt[2], "Marlon Brando");
strcpy(qtn[9].opt[3], "Ang Lee");

strcpy(qtn[10].opt[0], "University of Oxford");
strcpy(qtn[10].opt[1], "University of Cambridge");
strcpy(qtn[10].opt[2], "University of Bologna");
strcpy(qtn[10].opt[3], "Harvard University");

strcpy(qtn[11].opt[0], "Magadan");
strcpy(qtn[11].opt[1], "Vostok");
strcpy(qtn[11].opt[2], "Oymyakon");
strcpy(qtn[11].opt[3], "Maitree");

strcpy(qtn[12].opt[0], "Joseph Goebbels");
strcpy(qtn[12].opt[1], "Karl Donitz");
strcpy(qtn[12].opt[2], "Heinrich Himmler");
strcpy(qtn[12].opt[3], "Hermann Goring");

strcpy(qtn[13].opt[0], "Manchester United FC");
strcpy(qtn[13].opt[1], "Portsmouth AFC");
strcpy(qtn[13].opt[2], "Sunderland FC");
strcpy(qtn[13].opt[3], "Southampton FC");

strcpy(qtn[14].opt[0], "Rudyard Kipling");
strcpy(qtn[14].opt[1], "George Orwell");
strcpy(qtn[14].opt[2], "Ben Kingsley");
strcpy(qtn[14].opt[3], "Mahatma Gandhi");

//THE CORRECT OPTIONS
qtn[0].copt='A';
qtn[1].copt='C';
qtn[2].copt='B';
qtn[3].copt='D';
qtn[4].copt='B';
qtn[5].copt='A';
qtn[6].copt='C';
qtn[7].copt='B';
qtn[8].copt='A';
qtn[9].copt='B';
qtn[10].copt='C';
qtn[11].copt='B';
qtn[12].copt='A';
qtn[13].copt='B';
qtn[14].copt='C';

//FIFTY50 OPTIONS
qtn[0].fopt[0]=0;
qtn[0].fopt[1]=1;
qtn[1].fopt[0]=0;
qtn[1].fopt[1]=2;
qtn[2].fopt[0]=1;
qtn[2].fopt[1]=3;
qtn[3].fopt[0]=1;
qtn[3].fopt[1]=3;
qtn[4].fopt[0]=1;
qtn[4].fopt[1]=3;
qtn[5].fopt[0]=0;
qtn[5].fopt[1]=3;
qtn[6].fopt[0]=1;
qtn[6].fopt[1]=2;
qtn[7].fopt[0]=1;
qtn[7].fopt[1]=2;
qtn[8].fopt[0]=0;
qtn[8].fopt[1]=2;
qtn[9].fopt[0]=0;
qtn[9].fopt[1]=1;
qtn[10].fopt[0]=2;
qtn[10].fopt[1]=3;
qtn[11].fopt[0]=0;
qtn[11].fopt[1]=1;
qtn[12].fopt[0]=0;
qtn[12].fopt[1]=2;
qtn[13].fopt[0]=1;
qtn[13].fopt[1]=2;
qtn[14].fopt[0]=2;
qtn[14].fopt[1]=3;
}


char tic[3][3];               //global matrix declarations
int d,e,f,a,t,i,j,x,y;        //global variables declarations
int w=0;
void display();               //displays the matrix
void user();                  //function for user's move
void newdisp();               //function for display of matrix after every move
void pc();                    //function for pc's move
int check();                  //function for finding out the winner
int horcheck();               //function for horizontal line check
int vercheck();               //function for vertical line check
int diagcheck();              //function for diagonal line check
int donecheck();            //function to check for draw





//FUNCTIONS
void ask(int x)
{
system("pause");
clrscr();
cout<<"*************************   THE MILLIONAIRE JACKPOT   *************************"<<endl<<endl;
cout<<"\n \n Question number "<<x+1<<" on your screen now!! \n (Correct Answer: $ "<<qtn[x].valq<<", Wrong Answer: $ "<<qtn[x].valsaf<<", Quit: $ "<<qtn[x].valwon<<") \n \n"
	<<qtn[x].q<<endl
	<<"A: "<<qtn[x].opt[0]<<endl
	<<"B: "<<qtn[x].opt[1]<<endl
	<<"C: "<<qtn[x].opt[2]<<endl
	<<"D: "<<qtn[x].opt[3]<<endl<<endl
	<<"Enter your option (A/B/C/D): ";
cin>>qtn[x].popt;
test(x);
}

void test(int x)
{
if(qtn[x].popt=='1')
{
f50(x);
test(x);
}
else if(qtn[x].popt=='2')
{
audi(x);
test(x);
}
else if(qtn[x].popt==qtn[x].copt)
{
 sound(2000);
 delay(400);
 nosound();
 sound(3000);
 delay(500);
 nosound();
 cout<<" \n \n \n \n \n \n \n That is the correct answer!!! Well played!!! You have won $"<<qtn[x].valq<<endl;
}
else if(qtn[x].popt=='Q')
{
cout<<endl<<endl<<"The correct answer was: "<<qtn[x].copt<<endl<<endl;
pg=0;
qtn[x+1].valwon=qtn[x].valwon;
}
else
{
qtn[x+1].valwon=qtn[x].valsaf;
sound(80);
delay(400);
nosound();
sound(50);
delay(400);
nosound();
sound(80);
delay(400);
nosound();
cout<<"No!!!! That is the wrong answer!!!!! The correct answer was: "<<qtn[x].copt<<endl;
pg=0;
}
}

void f50(int x)
{
ffct++;
cout<<"\n You have chosen Fifty-Fifty. \n Your remaining options are: \n"
	<<char(qtn[x].fopt[0]+65)<<": "<<qtn[x].opt[qtn[x].fopt[0]]<<endl
	<<char(qtn[x].fopt[1]+65)<<": "<<qtn[x].opt[qtn[x].fopt[1]]<<endl<<endl;
if(ffct==2)
cout<<"You have taken Fifty-fity twice now. It is no longer available this question henceforth."<<endl;
cout<<"Enter your new option: ";
cin>>qtn[x].popt;
test(x);
}

void audi(int x)
{
apct++;
int cor= int (qtn[x].copt) - 65;
int ao[4]={15,15,15,15};
ao[cor]=55;
cout<<"\n You have chosen Audience Poll. \n Your results are: \n"
	<<"A: "<<ao[0]<<"%"<<endl
	<<"B: "<<ao[1]<<"%"<<endl
	<<"C: "<<ao[2]<<"%"<<endl
	<<"D: "<<ao[3]<<"%"<<endl<<endl;
if(apct==2)
cout<<"You have taken Audience Poll twice now. It is no longer available this question henceforth."<<endl;
cout<<"Enter your new option: ";
cin>>qtn[x].popt;
test(x);
}



void display()                //display function definition
{
 clrscr();
cout<<"*************************   THE MILLIONAIRE JACKPOT   *************************"<<endl<<endl;
 cout<<endl<<endl;
 for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
//figure formation
	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}

void user()                  //user function definition
{
 cout<<" ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' i.e 1,2,3"<<endl<<endl;
 cin>>x>>y;
 x--;
 y--;
 if((x<0)||(x>2)&&(y<0)||(y>2))  //check for valid co-ordinates
 {
  cout<<"ENTER THE CORRECT CO-ORDINATES";
  user();    //user function call
 }
 else
 {
  if(tic[x][y]==' ')    //check for vacant space at entered co-ordinates
  {
   tic[x][y]='X';  //assigning user 'X' to the co-ordinates
   newdisp();    //newdisp function call
  }
  else
  {
   cout<<"THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES";
   user();       //user function call
  }
 }
 d=check();            //check function call
 if(d==0)
  pc();                 //pc function call
 else if (d==1)
 {
  cout<<"YOU ARE THE WINNER";
  cout<<endl<<endl<<"Congratulations!! You have won $ "<<amt*3<<endl<<endl<<"Thank you for playing THE MILLIONAIRE JACKPOT Arunavha Chanda version!!";
  getche();     //requires enter to return to program. prevents return without display
  exit(1);      //program termination
 }
 else if (d==5)
 {
  cout<<"Game DRAWN!!"<<endl<<endl<<"Congratulations!! You have won $ "<<amt<<endl<<endl<<"Thank you for playing THE MILLIONAIRE JACKPOT Arunavha Chanda version!!";
  getche();
  exit(1);
 }
}

void newdisp()        //newdisp function definition
{
 clrscr();
 cout<<"*************************   THE MILLIONAIRE JACKPOT   *************************"<<endl<<endl;
 cout<<endl<<endl;
 for(t=0;t<3;t++)
 {
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
    //displays new tictactoe after user or pc turn
	if(t!=2)
	cout<<"		--|---|--"<<endl;
 }
}

void pc()          //pc function call
{
 int f,z;
 randomize();       //initialize random function calling
 cout<<"THIS IS THE COMPUTERS MOVE";
 for(i=0;i<=20;i++)
 {
  f=random(3);
  z=random(3);
  if(tic[f][z]==' ')      //check for vacant space at entered co-ordinates
  {
   tic[f][z]='O';  //assigning pc 'O' to the co-ordinates
   break;         //exiting for loop to display new tictactoe
  }
 }
 newdisp();                    //newdisp function call
 d=check();                      //check function call
 if(d==0)
  user();                         //user function call
 else if (d==1)
 {
  cout<<"YOU HAVE LOST!!!!!!!!!";
  cout<<endl<<endl<<"Sorry!! You have not won anything"<<endl<<endl<<"Thank you for playing THE MILLIONAIRE JACKPOT Arunavha Chanda version!!";
  getche();           //requires enter to return to program. prevents return without display
  exit(1);            //program termination
 }
 else if (d==5)
 {
  cout<<"Game DRAWN!!"<<endl<<endl<<"Congratulations!! You have won $ "<<amt<<endl<<endl<<"Thank you for playing THE MILLIONAIRE JACKPOT Arunavha Chanda version!!";
  getche();
  exit(1);
 }
}

check()                     //check function definition
{
 horcheck();                 //horcheck function call
 vercheck();                 //vercheck function call
 diagcheck();                //diagcheck function call
 donecheck();
 if (w==0 || (d||e||f)==1)
  return (d||e||f);
 else
  return w;
}

horcheck()                  //horcheck function definition
{
 if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])&&(tic[0][1]!=' '))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])&&(tic[1][1]!=' '))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])&&(tic[2][2]!=' ')))
      d=1;                        //checks each element of a horizontal line to be same
 else                        //returns 1 if all 3 elements of any horizontal line are same
      d=0;                        //else returns 0
 return d;
}

vercheck()                  //vercheck function definition
{
 if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])&&(tic[0][0]!=' '))||((tic[0][1]==tic[1][1])&&(tic[1][1]==tic[2][1])&&(tic[0][1]!=' '))||((tic[0][2]==tic[1][2])&&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' ')))
      e=1;                        //checks each element of a vertical line to be same
 else                        //returns 1 if all 3 elements of any vertical line are same
      e=0;                        //else returns 0
 return e;
}

diagcheck()                 //diagcheck function definition
{
 if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])&&(tic[0][0]!=' '))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' ')))
      f=1;                        //checks each element of a diagonal line to be same
 else                        //returns 1 if all 3 elements of any diagonal line are same
      f=0;                        //else returns 0
 return f;
}

donecheck()
{
 if(tic[0][0]!=' ' && tic[0][1]!=' ' && tic[0][2]!=' ' && tic[1][0]!=' ' && tic[1][1]!=' ' && tic[1][2]!=' ' && tic[2][0]!=' ' && tic[2][1]!=' ' && tic[2][2]!=' ')
 w=5;
 return w;
}




void main()
{
textbackground(WHITE); //set the background color
textcolor(BLACK);
clrscr();
textcolor(WHITE);
cout<<"*************************   THE MILLIONAIRE JACKPOT   *************************"<<endl<<endl;
textcolor(BLACK);
cout<<"WELCOME TO THE MILLIONAIRE JACKPOT!!! \n \n RULES: \n \n"
	<<"1. THERE WILL BE 15 QUESTIONS FROM $ 500 TO $ 7 MILLION. \n"
	<<"2. THERE ARE 2 SAFE HAVENS AT Q.NO. 4 ($ 4,000) AND Q.NO. 8 ($ 64,000). ANSWERING A QUESTION WRONG WILL WIN YOU THE AMOUNT OF THE LAST HAVEN AND IF YOU QUIT, YOU WILL WIN TILL THE LAST-ANSWERED QUESTION. \n"
	<<"3. YOU HAVE ONLY 2 LIFELINES, BOTH OF WHICH YOU CAN USE TWICE. 50-50 AND AUDIENCE POLL. \n"
	<<"4. TO ANSWER A QUESTION, PLEASE ENTER YOUR OPTION CODE (A/B/C/D) ONLY IN CAPITALS. \n"
	<<"5. TO USE A LIFELINE, ENTER LIFELINE NO. (1 FOR FIFTY-FIFTY AND 2 FOR AUDIENCE POLL). \n"
	<<"6. TO QUIT, ENTER CAPITAL Q. \n"
	<<"7. AFTER THE QUIZ, YOU CAN PLAY A JACKPOT ROUND OF TIC-TAC-TOE \n"
	<<"8. IF YOU WIN, YOU GET 3 TIMES YOUR PRIZE AMOUNT\n"
	<<"9. IF YOU DRAW, YOU GET THE SAME AMOUNT \n"
	<<"10. IF YOU LOSE, YOU GET ZERO \n \n";
 sound(400);
 delay(300);
 nosound();
 sound(600);
 delay(300);
 nosound();
 sound(1000);
 delay(300);
 nosound();
 sound(400);
 delay(300);
 nosound();
 sound(600);
 delay(300);
 nosound();
 sound(1000);
 delay(300);
 nosound();
 sound(1500);
 delay(700);
 nosound();
int i=0;
assign(qtn);
for(i=0;i<15 && pg==1;i++)
{
ask(i);
}
amt=qtn[i].valwon;
cout<<endl<<endl<<"Congratulations!! You have won $ "<<amt<<endl;
getche();
clrscr();
char choice;
cout<<"*************************   THE MILLIONAIRE JACKPOT   *************************"<<endl<<endl;
cout<<"Will you play the jackpot round????!!! (Y/N)"<<endl;
cin>>choice;
if (choice=='N')
cout<<endl<<endl<<"Congratulations!! You have won $ "<<amt<<endl<<endl<<"Thank you for playing THE MILLIONAIRE JACKPOT Arunavha Chanda version!!";
else if (choice=='Y')
{
 clrscr();                     //clears the previous output screen
 randomize();                  //initialize random function calling
 int d=random(2);              //random function call
 for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	tic[i][j]=' ';        //assigning space ' ' to all elements of matrix
 display();                    //display function call
 d==0?user():pc();             //random starting of the game depending on d
}
getch();
closegraph();
}
