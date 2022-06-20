#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <iostream>

char a[3][3];

const char igrac1='X';
const char igrac2='O';
const char ai='O';	

void  nova_tabla()
{
int i,j;
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		a[i][j]=' ';
	}
}
}
	void ispis_table()
	{
	printf(" %c | %c | %c",a[0][0],a[0][1],a[0][2]);
    printf("\n---|---|---\n");
	printf(" %c | %c | %c",a[1][0],a[1][1],a[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c",a[2][0],a[2][1],a[2][2]);
printf("\n");
	}
void potezi2 ()
		{
			int i,j;
			p:
			printf("unesite poziciju na kojoj zelite da unesete o\n ");
			printf("unesi red\n");
			scanf("%d",&i);
			i--;
			printf("unesi kolonu\n");
				scanf("%d",&j);
			j--;
			do
				{
				if(a[i][j]!=' ')
					{
					printf("Polje koje ste izabrali je zauzeto,pokusajte opet\n");
					goto p;
					}
						else
						{

						a[i][j]=igrac2;
						break;
			
						}	
				}while(a[i][j]!=' ');
			
		}

		void potezi1 ()
		{
			
			int i,j;
			p:
			printf("unesite poziciju na kojoj zelite da unesete x\n ");
			printf("unesi red\n");
			scanf("%d",&i);
			i--;
			printf("unesi kolonu\n");
				scanf("%d",&j);
			j--;
			do
				{
				if(a[i][j]!=' ')
					{
					printf("Polje koje ste izabrali je zauzeto,pokusajte opet\n");
					goto p;
					}
						else
						{

						a[i][j]=igrac1;
						break;
			
						}	
				}while(a[i][j]!=' ');
			
		}
		int provera_metsa()
					{
						int i,j;
						int  mesto=9;
						for(i=0;i<3;i++)
							{
							for(j=0;j<3;j++)
								{
									if(a[i][j]!=' ')
									{
										mesto--;	
									}
								}
							}
							return mesto;
					}
					void ispis_pobednika(char pobednik)
					{
						if(pobednik==igrac1)
						{
							printf("Pobedio si!\n");
							
						}
						else if (pobednik==ai)
						{
						
								printf("pobedio je ai\n");
	
						}
						else
							{
								printf("Nereseno je!\n");
							
							}
	
					}
	
				void potezi_ai()
				{		
				
							srand(time(0));
							int i,j;
							if(provera_metsa()>0)
							{
								do
								{
									i=rand()%3;
									j=rand()%3;
								}while(a[i][j]!=' ');
								
								  a[i][j]=ai;
							}
							else
							{
								ispis_pobednika(' ');
							}
							
					}
					char provera_pobednika()
					{
						//ispitivanje redova
						int i;
						for(i=0;i<3;i++)
						{
							if((a[i][0]==a[i][1])&&(a[i][1]==a[i][2]))
							return a[i][0];
						}
						//ispitivanje kolona
							for(i=0;i<3;i++)
							{
								if((a[0][i]==a[1][i])&&(a[i][0]==a[2][i]))
								return a[0][i];
							}
							//provera prve dijagonale
					
									if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))
									return a[1][1];
							
									//provera druge dijagonale	
									if((a[0][2]==a[1][1])&&(a[1][1]==a[2][0]))
									{
									
										return a[1][1];
									}
									else
									return ' ';
									
					
					}
					
					
					void ispis_pobednika2(char pobednik)
					{
						if(pobednik==igrac1)
						{
							printf("Pobedio je prvi igrac!\n");
							
						}
						else if (pobednik==igrac2)
						{
						
								printf("pobedio je drugi igrac\n");
	
						}
						else
							{
								printf("Nereseno je!\n");
							
							}
	
					}
int main() 

{
int l;

printf("\n");
printf("dobrodosli u iks oks\n");
printf("molimo vas izaberite mod igre:\n");
printf("1-igrac vs ai\n");
printf("2-igrac vs igrac\n");


scanf("%d",&l);

char pobednik=' ';
if(l==1)
{
	printf("izabrali ste mod %d\n",l);
printf("pozicije idu po sledecim koordinatama:\n");
printf("%d|%d|%d\n",11,12,13);
printf("--|--|--\n");
printf("%d|%d|%d\n",21,22,23);
printf("--|--|--\n");
printf("%d|%d|%d\n",31,32,33);
		printf("\n\n\n");
nova_tabla();
while(pobednik==' '&&provera_metsa()!=0)
{
	ispis_table();
	potezi1();
	
	pobednik=provera_pobednika();
	if(pobednik!=' ' || provera_metsa()==0)
	{
		break;
	}
	potezi_ai();
	pobednik=provera_pobednika();
	if(pobednik!=' ' || provera_metsa()==0)
	{
		break;
	}	
}
ispis_table();
ispis_pobednika(pobednik);
}
else
{
	printf("izabrali ste mod %d\n",l);
	printf("pozicije idu po sledecim koordinatama:\n");
printf("%d|%d|%d\n",11,12,13);
printf("--|--|--\n");
printf("%d|%d|%d\n",21,22,23);
printf("--|--|--\n");
printf("%d|%d|%d\n",31,32,33);
		
nova_tabla();
while(pobednik==' '&&provera_metsa()!=0)
{
	ispis_table();
	potezi1();
	pobednik=provera_pobednika();
	if(pobednik!=' ' || provera_metsa()==0)
	{
		break;
	}
	ispis_table();
	potezi2();
	pobednik=provera_pobednika();
	if(pobednik!=' ' || provera_metsa()==0)
	{
		break;
	}	
}
ispis_table();
ispis_pobednika2(pobednik);
}
	return 0;
}
