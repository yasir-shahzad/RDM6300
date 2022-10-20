#include <TimerOne.h>
//***********************************************************
//.................(DEFINING THE VARIABLE)...................
//***********************************************************

unsigned char rx_data=0, flag[31], flag1=0;
int                id=0, id1=0; 
unsigned char card[]={"            "};
//unsigned char card[]={"130049B044AE"};
//***********************************************
unsigned char card1[12]={'3','7','0','0','8','0','4','4','6','A','9','9'};
unsigned char card2[12]={'3','7','0','0','8','0','9','2','A','B','8','E'};
unsigned char card3[12]={'3','7','0','0','8','0','9','2','D','D','F','8'};
unsigned char card4[12]={'3','9','0','0','8','9','1','6','7','3','D','5'};
unsigned char card5[12]={'3','9','0','0','3','A','0','6','7','C','7','9'};
unsigned char card6[12]={'3','9','0','0','8','9','1','9','9','B','3','2'};
unsigned char card7[12]={'3','9','0','0','3','9','7','F','5','B','2','4'};
unsigned char card8[12]={'3','7','0','0','8','0','2','D','C','D','5','7'};
unsigned char card9[12]={'3','7','0','0','8','0','2','D','D','E','4','4'};
unsigned char card10[12]={'3','9','0','0','8','9','2','E','F','4','6','A'};
//***********************************************
unsigned char card11[12]={'3','9','0','0','8','9','2','F','F','A','6','5'};
unsigned char card12[12]={'3','9','0','0','3','A','0','7','7','8','7','C'};
unsigned char card13[12]={'3','9','0','0','3','8','B','9','3','4','8','C'};
unsigned char card14[12]={'3','9','0','0','3','8','A','3','3','E','9','C'};
unsigned char card15[12]={'3','9','0','0','8','9','2','8','9','4','0','C'};
unsigned char card16[12]={'3','7','0','0','7','E','7','C','6','D','5','8'};
unsigned char card17[12]={'3','7','0','0','8','0','3','7','4','5','C','5'};
unsigned char card18[12]={'3','7','0','0','8','0','1','5','D','8','7','A'};
unsigned char card19[12]={'3','7','0','0','8','0','8','7','7','9','4','9'};
unsigned char card20[12]={'3','7','0','0','8','0','9','2','E','E','C','B'};
//***********************************************
unsigned char card21[12]={'3','7','0','0','7','E','7','E','5','C','6','B'};
unsigned char card22[12]={'3','7','0','0','7','E','5','D','E','0','F','4'};
unsigned char card23[12]={'3','9','0','0','3','9','B','C','5','D','E','1'};
unsigned char card24[12]={'3','9','0','0','3','9','B','C','9','2','2','E'};
unsigned char card25[12]={'3','9','0','0','3','9','B','C','8','E','3','2'};
unsigned char card26[12]={'3','9','0','0','3','9','9','5','8','9','1','C'};
unsigned char card27[12]={'3','9','0','0','3','9','D','B','4','1','9','A'};
unsigned char card28[12]={'3','7','0','0','8','0','1','8','1','1','B','E'};
unsigned char card29[12]={'3','9','0','0','3','9','D','B','7','5','A','E'};
unsigned char card30[12]={'3','9','0','0','3','9','C','A','B','F','7','5'};

long time1,time2,far;
/*------------------------------------------------*/
//pointers vs arrays
unsigned char check(unsigned char *first, unsigned char *second, unsigned char add , unsigned char len)   //first and second are the string decleared
    {
     unsigned char i=0;
     for(i=add;i<len;i++)
        {
	      if(first[i]!=second[i])     //maching the adresses of varibles
	      return 0; 
	    }
     return 1;
    }
//*--------------------read card-----------------`````````````~~~~~~~~~~~~~~~~
unsigned char read_card(){
time2=100;                                 //mean 1sec to the time2 to be zero
while(1){
looop:
if(Serial.available() > 0){
time1=30;                    //300ms                     
while(Serial.read()!= 2)     //mean received some data and wait for the come of 2 for further processing.  here 2 is start of message 
    {                        //receivd some data wait for 2 detection unless data is coming and putting the data in garbege.
	                        // if there is no 2 and data has ended then check whether 300ms has passed or not from the data detection
     while(Serial.available() == 0)          //if there is no data coming to the serial port
        {
	      if(!time1){goto looop;}           //after 300msec the timer1 will be equal to zero so the program will shift to the loop
		}
    }
//*****************read card****************
for(far=0;far<12;far++)
{
  time1=20;    //mean we received some digits out of 12 if remaining digits never come then wait 200ms if again not then go to loop.
  while(!Serial.available())     //if there's nothing on the serial port
    { 
       if(!time1){goto looop;}     //after 200msec it will shift to the loop;
    }
card[far]= Serial.read();
}
//*****************mach card**********
     if(check(card,card1,3,12)){flag[1]=1;return 1;}
else if(check(card,card2,3,12)){flag[2]=1;return 2;}
else if(check(card,card3,3,12)){flag[3]=1;return 3;}
else if(check(card,card4,3,12)){flag[4]=1;return 4;}
else if(check(card,card5,3,12)){flag[5]=1;return 5;}
else if(check(card,card6,3,12)){flag[6]=1;return 6;}
else if(check(card,card7,3,12)){flag[7]=1;return 7;}
else if(check(card,card8,3,12)){flag[8]=1;return 8;}
else if(check(card,card9,3,12)){flag[9]=1;return 9;}
else if(check(card,card10,3,12)){flag[10]=1;return 10;}
else if(check(card,card11,3,12)){flag[11]=1;return 11;}
else if(check(card,card12,3,12)){flag[12]=1;return 12;}
else if(check(card,card13,3,12)){flag[13]=1;return 13;}
else if(check(card,card14,3,12)){flag[14]=1;return 14;}
else if(check(card,card15,3,12)){flag[15]=1;return 15;}
else if(check(card,card16,3,12)){flag[16]=1;return 16;}
else if(check(card,card17,3,12)){flag[17]=1;return 17;}
else if(check(card,card18,3,12)){flag[18]=1;return 18;}
else if(check(card,card19,3,12)){flag[19]=1;return 19;}
else if(check(card,card20,3,12)){flag[20]=1;return 20;}
else if(check(card,card21,3,12)){flag[21]=1;return 21;}
else if(check(card,card22,3,12)){flag[22]=1;return 22;}
else if(check(card,card23,3,12)){flag[23]=1;return 23;}
else if(check(card,card24,3,12)){flag[24]=1;return 24;}
else if(check(card,card25,3,12)){flag[25]=1;return 25;}
else if(check(card,card26,3,12)){flag[26]=1;return 26;}
else if(check(card,card27,3,12)){flag[27]=1;return 27;}
else if(check(card,card28,3,12)){flag[28]=1;return 28;}
else if(check(card,card29,3,12)){flag[29]=1;return 29;}
else if(check(card,card30,3,12)){flag[30]=1;return 30;}
}
if(!time2){return 0;} //if the time2 is equal to zero then return the 0
} //End of while(1)
} //End of read_card()



//****************************************
void setup() 
{
//10000 = 10ms
Timer1.initialize(10000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
Timer1.attachInterrupt( timerIsr ); // attach the service routine here
Serial.begin(9600);
}

void loop() {
//*********************************

 id = read_card();
 if(id != id1){
 Serial.write(id);
 id1 = id;
 }
//*********************************
//for(int i=0;i<30;i++){flag[i] = 0;}

}


//***************************
void timerIsr()
{
if(time1 > 0){time1--;}
if(time2 > 0){time2--;}
}

