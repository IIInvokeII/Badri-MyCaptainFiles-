#include<stdio.h>
int main()
{
  int choice=0;
  printf("Food Choice \n Enter any number between 1 and 5 to be surprised! : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: printf("\nItem: Authentic Japanese Style Ramen\nCost: Rs.450"); break;
    case 2: printf("\nItem: French Toast + Marmalade\nCost: Rs.499"); break;
    case 3: printf("\nItem: Red Velvet Ice Cream Cake\nCost: Rs.299 per piece"); break;
    case 4: printf("\nItem: Fugu Sashimi\nCost: Rs.2,199"); break;
    case 5: printf("\nItem: Extremely Spicy Mapo Tofu\nCost: Rs.899"); break;
    default: printf("Invalid Choice.");
  }
  return 0;
}
