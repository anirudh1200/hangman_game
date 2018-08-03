#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define clear() printf("\033[H\033[J")

int getin(int,int);
void instruct();
void thank();
void p();
void takename();
int score();

char name1[20],name2[20];
int p1=0, p2=0;

/*
_____________
       |     |
       0     |
       |     |
      /|\    |
       |     |
	  / \	 |
_____________|____
*/
int main() {
	int g=1,x=0;
	instruct();
	takename();
	while(g!=0) {
		p1=p1+getin(1,2);
		x=score();
		if(x==1) {
			break;
		}
		p2=p2+getin(2,1);
		x=score();
		if(x==1) {
			break;
		}
	}
	thank();
	return 0;
}

int getin(int x,int y) {
	int alpha,word,i,d=8,j=0,dupl=0,k=0,dupl1=0;
	int change=0,tchange=0,point=0;
	char ch[100],cha[100],c,b,w[26], hint[100];
	char hang[7]={'0','|','/','|','/','|','/'},h[7]={' ',' ',' ',' ',' ',' '};
	clear();
	RET: p();
	printf("\n\n\tPlayer %d enter any words or phase (max 3 words) : ",y);
	scanf(" %[^\n]s",ch);
	printf("\n\n\tEnter a hint (optional) : ");
	scanf(" %[^\n]s",hint);
	word = 0;
	alpha = 0;
	i=0;
	while(ch[i]!='\0') {
		alpha++;
		if(ch[i]==' ') {
			word++;
		}
		i++;
	}
	word=word+1;
	alpha=alpha;

	if(word<4) {
		for(i=0;i<alpha;i++) {
			if(ch[i]==' ') {
				cha[i]=' ';
			} else {
				cha[i]='_';
			}
		}

		while(d>0) {
			clear();
			p();
			printf("\t\t_____________\n");
			printf("\t\t       |     |\n\t\t       |     |\n");
			printf("\t\t       %c     |\n",h[0]);
			printf("\t\t       %c     |\n",h[1]);
			printf("\t\t      %c%c%c    |\n",h[2],h[3],h[4]);
			printf("\t\t       %c     |\n",h[5]);
			printf("\t\t       %c     |\n",h[5]);
			printf("\t\t      %c %c    |\n\t\t             |\n",h[6],h[6]);
			printf("\t\t_____________|___\n");

			printf("\n\tHint : %s\n\n", hint);
			printf("\tYou have %d chances Left !!!",d);
			printf("\n\n\t|");
			for(i=0;i<alpha;i++) {
				printf("%c|",cha[i]);
			}
			printf("\n\n\tYou have already entered :");
			for(k=0;k<j;k++) {
				printf(" %c",w[k]);
			}
			printf("\n\n\tEnter a letter : ");
			scanf(" %c",&c);
			change=0;
			dupl=0;
			dupl1=0;
			for(i=0;i<alpha;i++) {
				if(cha[i]==c) {
					dupl++;
					}
			}
			for(i=0;i<=j;i++) {
				if(w[i]==c) {
					dupl1++;
				}
			}
			if(dupl==0&&dupl1==0) {
				for(i=0;i<alpha;i++) {
					if(c==ch[i]) {
						cha[i]=ch[i];
						change++;
						tchange++;
				 	}
				}
				if(tchange==alpha-word+1) {
					clear();
					p();
					printf("\n\n\tThe word was : \t");
					for(i=0;i<alpha;i++) {
						printf("%c",ch[i]);
					}
					printf("\n\n\tYou won !!! :)");
					printf("\n\n\tCongratulations");
					point=1;
					break;
				} else if(d==1) {
					clear();
					p();
					printf("\t\t_____________\n");
					printf("\t\t       |     |\n\t\t       |     |\n");
					printf("\t\t       %c     |\n",hang[0]);
					printf("\t\t       %c     |\n",hang[1]);
					printf("\t\t      %c%c%c    |\n",hang[2],hang[3],hang[4]);
					printf("\t\t       %c     |\n",hang[5]);
					printf("\t\t       %c     |\n",hang[5]);
					printf("\t\t      %c %c    |\n\t\t             |\n",hang[6],hang[6]);
					printf("\t\t_____________|___\n\n\n");
					printf("\n\n\tYou entered : \n\n\t");
					for(i=0;i<alpha;i++) {
						printf("%c",cha[i]);
					}
					printf("\n\n\n\tThe word was : \n\n\t");
					for(i=0;i<alpha;i++) {
						printf("%c",ch[i]);
					}
					printf("\n\n\n\tYou lost !!! :(\n\n");
					point=0;
					break;
				} else if(change==0) {
					d--;
					w[j]=c;
					j++;
					h[j-1]=hang[j-1];
				} else {}
			} else {}
		}
	} else
	{
		clear();
		p();
		printf("\n\n\n----- You can enter only a maximum of four words-----");
		printf("\n\n\n----- Press any key to retry !!! -----");
		scanf("%c",&c);
		scanf("%c",&c);
		clear();
		goto RET;
	}

	printf("\n\n\n   ______ -----  Press Any Key To Continue  ----- ______\n\n\n");
	scanf("%c",&c);
	scanf("%c",&c);
	clear();

	return point;
}

void instruct() {
	char o;
	clear();
	p();
	printf("                                                   - By Anirudh\n\n\n");
	printf("\t----- INSTRUCTIONS -----\n");
	printf("\t1. This is a 2 player game\n");
	printf("\t2. 1st player has to write a word or phrase and 2nd player has to guess it\n");
	printf("\t3. Each player will get 8 a maximum of chances to gess alphabets\n");
	printf("\t4. The player with more points wins");
	printf("\n\n\tBest of luck !!!");
	printf("\n\n\n\n\t--- Press Any Key to continue ---");
	scanf("%c",&o);
}

int score() {
	char d;
	p();
	printf("\n\n\n\t ___---  S C O R E S  ---___ \n\n\t");
	printf("%s : %d\n\n\t",name1,p1);
	printf("%s : %d",name2,p2);
	printf("\n\n\n   ______ -----  Press Any Key To Continue  ----- ______\n\n\n");
	printf("\n\n\n   ______ -----  To EXIT press x  ----- ______\n\n\n");
	scanf("%c",&d);
	clear();
	if(d=='x') {
		return 1;
	} else {
		return 0;
	}
}

void thank() {
	char m;
	clear();
	p();
	printf("\n\n\n\t\t_____-----THANK YOU-----_____ ");
	printf("\n\n\n\t--- Press Any Key to continue ---");
	scanf("%c",&m);
	clear();
}

void p() {
	printf("\n\n\n\t_____________________ -----  H A N G M A N  ----- _____________________\n\n");
}

void takename() {
	clear();
	p();
	printf("Enter name of Player 1 : ");
	scanf("%[^\n]s",name1);
	printf("Enter name of Player 2 : ");
	scanf(" %[^\n]s",name2);
}
