#include<bits/stdc++.h>
using namespace std;
int sticks_1=0;
int min_max(int n ,int maximum)
{
	int depth,i,k;
	if(maximum==1)
	{
		depth=0;
		if(n==1) return 0;
		if(n==2) return 1;
		for(i=n-1;i>=n-3&&i>=1;i--)
		{
			depth=min_max(i,0);
			if(depth==1)
			{
				sticks_1=(n-i);
				break;
			}
		}
	return depth;
	}
	else
	{
		depth =1;
		if(n==1) return 1;
		if(n==2) return 0;
		for(i=n-1;i>=n-3&&i>=1;i--)
		{
			depth=min_max(i,1);
			if(depth==0)
			{
				break;
			}
		}
	return depth;
	}
}
void AI_vs_player(int n)
{
	int computer_1,Player_1;
	int t,rest_sticks=n,sticks;
	t=rand()%2;
	if(t)printf("\nComputer_1 HAS WON THE TOSS:\n");
	else printf("\nPlayer_1 HAS WON THE TOSS:");
	while(1)
	{
		if(!t)
		{
			t: printf("\nPlayer_1:");
			scanf("%d",&sticks);
			if(sticks<1 || sticks>3 || sticks>rest_sticks)
			{
				printf("\n NOT PERMITED.TRY AGAIN");
				goto t;
			}
		rest_sticks-=sticks;
		t=1;
		}
		else
		{
			sticks_1=0;
			printf("computer_1:");
			min_max(rest_sticks,1);
			if(sticks_1!=0)
			{
				printf("%d",sticks_1);
				rest_sticks-=sticks_1;
			}
			else
			{
				printf("1");
				rest_sticks--;
			}
			t=0;
		}
		if(rest_sticks==1)
		{
			if(!t)cout<<"\nComputer_1 won the game";
			else cout<<"\nPlayer_1 won the game";
			break;
		}
	}
}
void AI_vs_AI(int n)
{
	int computer_1,computer_2;
	int t,rest_sticks=n,sticks;
	t=rand()%2;
	if(t)printf("\nComputer_1 HAS WON THE TOSS:");
	else printf("\nComputer_2 HAS WON THE TOSS:");
	while(1)
	{
		if(!t)
		{
			printf("\nCOMPUTER_2:");
			min_max(rest_sticks,1);
			printf("%d",sticks_1);
			rest_sticks-=sticks_1;
			t=1;
		}
		else
		{
			printf("\ncomputer_1:");
			min_max(rest_sticks,1);
			printf("%d",sticks_1);
			rest_sticks-=sticks_1;
			t=0;
		}
		if(rest_sticks==1)
		{
			if(!t)cout<<"\nComputer_1 won the game";
			else cout<<"\nComputer_2 won the game";
			break;
		}
	}
}
int main(){
int n,ch;
while(1)
{
	printf("\n HOW MUCH STICK WITH YOU WANT TO PLAY:\n");
	scanf("%d",&n);
	printf("\n1. PLAY WITH COMPUTER");
	printf("\n2. PLAY COMPUTER VS COMPUTER");
	printf("\n3. EXIT");
	printf("\n4. ENTER YOUR CHOICE:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		AI_vs_player(n);
		break;
		case 2:
		AI_vs_AI(n);
		break;
		case 3:
		exit(0);	
		break;
		default:
		printf("\n ENTER THE RIGHT CHOICE");
		break;
	}
}
return 0;
}