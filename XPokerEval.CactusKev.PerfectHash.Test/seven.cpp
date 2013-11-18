#include <stdio.h>
#include <stdlib.h>
#include "../util/tchar.h"
#include <iostream>
#include "../XPokerEval.CactusKev.PerfectHash/poker.h"
#include "../util/Timer.h"

/*************************************************/
/*                                               */
/* This code tests my evaluator, by looping over */
/* all 2,598,960 possible five card hands, cal-  */
/* culating each hand's distinct value, and dis- */
/* playing the frequency count of each hand type */
/*                                               */
/* Kevin L. Suffecool, 2001                      */
/* suffecool@bigfoot.com                         */
/*                                               */
/*************************************************/

int _tmain(int argc, _TCHAR* argv[])
{
   int deck[52], hand[7], freq[10];
   int y, z, a, b, c, d, e, i, j;

   // initialize the deck
   init_deck( deck );

   // zero out the frequency array
   for ( i = 0; i < 10; i++ )
      freq[i] = 0;

   printf("Cactus Kev's Hand Evaluator with Perfect Hash by Paul Senzee\n");
   printf("------------------------------------------------------------\n\n");
   printf("Enumerating and evaluating all ??? unique seven-card poker hands...\n\n");

   Timer hftimer;
   hftimer.start();

   // loop over every possible seven-card hand
   for(y=0;y<46;y++) 
   {
      printf("Y: %d \n", y);
      hand[0] = deck[y];
      for(z=y+1;z<47;z++)
      {
	 hand[1] = deck[z];
	 for(a=z+1;a<48;a++)
	 {
	    hand[2] = deck[a];
	    for(b=a+1;b<49;b++)
	    {
	       hand[3] = deck[b];
	       for(c=b+1;c<50;c++)
	       {
		  hand[4] = deck[c];
		  for(d=c+1;d<51;d++)
		  {
		     hand[5] = deck[d];
		     for(e=d+1;e<52;e++)
		     {
			hand[6] = deck[e];

			i = eval_7hand( hand );
			j = hand_rank(i);
			freq[j]++;
		     }
		  }
	       }
	    }
	 }
      }
   }

   hftimer.stop();

   for(i=;i<=9;i++)
      printf( "%15s: %8d\n", value_str[i], freq[i] );

   int totalHands = 0;
   for (int category = 0; category < 10; category++)
      totalHands += freq[category];
   printf("\nEnumerated and evaluated %d hands in %f milliseconds", totalHands, hftimer.getElapsedTimeInMilliSec());

}

