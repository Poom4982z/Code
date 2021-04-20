#include <stdio.h>

int price[20];
char foodName[20][40];
int price[20],total=0,bill[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void rData();
void printPatternMenu();
void Calculatefood();
void printPatternbill();
void Calculatechange();

int main(){
	rData();
	while(1){
	system("cls");
	printPatternMenu();
	Calculatefood();
	printPatternbill();
	Calculatechange();
	}
}

void rData(){
    FILE *fp;
    fp = fopen("menu.txt","r");
	int i;
    for (i = 0 ; i < 20 ; i++){
        fscanf(fp,"%s %d", foodName[i],&price[i]);
    }
    fclose(fp);
}
void printPatternMenu(){
	int i =0;
	printf("*****************************************************************************************************************\n");
	printf("*                           ######     #####     ##    ##   #######       #       ##   ##                       *\n");
	printf("*                           #          #   #     #  # # #      #         # #      # # # #                       *\n");
	printf("*                           #####      #   #     #   #  #      #        #####     #  #  #                       *\n");
	printf("*                                #     #   #     #      #      #       #     #    #     #                       *\n");
	printf("*                           ######     #####     #      #      #      #       #   #     #                       *\n");
	printf("*****************************************************************************************************************\n\n");

	printf("#################################################################################################################\n");
	printf("#                                                       |                                                       #\n");
	printf("#                                                       |                                                       #\n");
	while (i < 20){
        printf("#  [%2d] %-40s %4d B\t", i+1, foodName[i], price[i]);
        i++;
        printf("| [%2d] %-40s %4d B  #\n", i+1, foodName[i], price[i]);
        i++;
    }
    printf("#                                                       |                                                       #\n");
    printf("#                                                       |                                                       #\n");
    printf("#################################################################################################################\n\n");

}
void Calculatefood(){
	int totalnumber,i=0,indexfood,amount;
	while(1){
		printf("Enter Total number of menu : ");
		scanf("%d",&totalnumber);
		if(totalnumber > 0 ){
			break;
		}
		printf("---Out of range!!!---\nTry again ");
	}

	while(i<totalnumber){
		while(1){
			printf("Enter the food number(1-20) : ");
			scanf("%d",&indexfood);
			if(indexfood>=1 && indexfood<=20)	{
				break;
			}
			printf("---Out of range!!!---\nTry again ");
		}
		indexfood-=1;
		printf("%s --> Enter Amount of food : ",foodName[indexfood]);
		scanf(" %d",&amount);
		bill[indexfood]+=amount;
		total += price[indexfood]*amount;
		i++;
	}
}
void printPatternbill(){
	system("cls");
	int i = 0 ,j=1;
    while (i < 20){
    	if(bill[i]>0){
    	printf("%2d : %-40s %4d B\n",j++, foodName[i], price[i]*bill[i]);
		}
		i++;
    }
    printf("total = %5d B\n",total);
}
void Calculatechange(){
	int money,summoney=0,i,j=0;
	while(1){
		printf("Enter money : ");
		scanf(" %d",&money);
		summoney += money;
		if(summoney>=total){
			break;
		}
		printf("Money is less than the total price. Please pay extra.\n");
	}
	printf("Change = %d B\n",summoney-total);
	do{
		printf("Enter [0] = exit : ");
		scanf("%d",&i);
	}while(i != 0);
	total = 0;
	while(j<20){
		bill[j++] = 0;
	}
}
