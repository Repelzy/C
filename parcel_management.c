#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



void quantity(int *num)
{
	int i;
	do
	        {
	        	printf("Nhap so kien hang da cung cap: ");
	            scanf("%d", num);
	            i = sizeof(num) / sizeof(int);
		        if(i < 1 || i > 100) printf("Nhap loi!\n");	
		        else 
		        {
		        	printf("\n");
		        	break;
		       	}        
            }
	while(i < 1 || i > 100);
} 


 struct Parcel
{
	char ParcelCode[20];                             //Ma kien hang
	float L, W, H;                                   //Kinh thuoc
	float Weight;                                    //Trong luong
	int TypeOfTransport;                             //Loai van chuyen
} ;



void InputParcel(struct Parcel *prc)                 //Nhap du lieu 
{
	    char *str;
	    do
	    {
	    	printf(" +Nhap ma kien hang (8 den 20 ki tu): ");
	        scanf("%s", prc->ParcelCode);
	        str = prc->ParcelCode;
	        if( (strlen(str) < 8 || strlen(str) > 20) &&(isalnum(str)) )	 printf("Nhap loi! ");
	        else break;      
	    }
	    while (strlen(str) < 8 || strlen(str) > 20);
        
	    printf(" +Nhap kich thuoc theo thu tu (L W H): ");
	    scanf("%f%f%f", &prc->L, &prc->W, &prc->H);
	    printf(" +Nhap trong luong tinh cua kien hang:  ");
	    scanf("%f", &prc->Weight);
	    do 
	    {
	    	printf(" +Nhap loai van chuyen (0 hoac 1): ");
	        scanf("%d", &prc->TypeOfTransport);
		    if(prc->TypeOfTransport != 0 && prc->TypeOfTransport != 1) printf("Nhap loi! ");
		    else break;
	    }
	    while (prc->TypeOfTransport != 0 && prc->TypeOfTransport != 1);     
	    printf("\n");	
}

void InputParcelList(struct Parcel prc[], int num)
{
	for (int k = 1; k <= num; k++) 
	 {
	 	printf("Kien hang thu %d\n", k);
		InputParcel(&prc[k]);
     }
}


int ErrorCode(struct Parcel prc)          //Kiem tra 2 (?)
{
    if ( (prc.L < 10) || (prc.W < 10) || (prc.H < 10) ) return 1;
    else if ((prc.L > 150) || (prc.W > 150) || (prc.H > 150))  return 2;
    else if (prc.Weight > 30) return 3;
    else return 0;
}


float ChargedWeight(struct Parcel prc)  // Kiem tra 3
{
	float cw;
	float sum = prc.L + prc.W + prc.H;
	if (sum < 80) cw = prc.Weight;
	else 
	{
		float ConvertWeight;
		if (prc.TypeOfTransport == 1) ConvertWeight = prc.L * prc.W * prc.H / 6000;
		if (prc.TypeOfTransport == 0) ConvertWeight = prc.L * prc.W * prc.H / 4000;
		cw = (prc.Weight > ConvertWeight) ? prc.Weight : ConvertWeight;
	}
	float frac = cw - (int)cw;
	if (frac == 0) return cw;
	else if (frac < 0.5) return (int)cw + 0.5;
	else return (int)cw + 1;
}


int cost(struct Parcel prc)
{
   float CW = ChargedWeight(prc);
    int c;
    if (prc.TypeOfTransport == 0)
    {
        if (CW <= 3)  c = 16500;
        else c = 16500 + (CW - 3) * 5000;
    }
    if (prc.TypeOfTransport == 1)
    {
        if (CW <= 3)  c = 22000;
        else c = 22000 + (CW - 3) * 5000;          
    }
    return c;
}


char* printWithComma(int num)               // Dau phay ngan cach
{
	char str[20];
    sprintf(str, "%d", num);
    int len = strlen(str);
    int commaCount = (len - 1) / 3;
    int newLen = len + commaCount;
    char* result = (char*)malloc((newLen + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < len; i++) {
        result[j++] = str[i];
        if ((len - i - 1) % 3 == 0 && i != len - 1) {
            result[j++] = ',';
        }
    }
    result[j] = '\0';
    return result;
} 


char* PrintCost(int num)               // Tinh tien
{
    return printWithComma(num);
}


char* print_tot(struct Parcel prc)
{
	if (prc.TypeOfTransport == 1) return "Chuyen nhanh";
	if (prc.TypeOfTransport == 0) return "Chuyen thuong";
}


int main()
{
	int n;
	struct Parcel ParcelList[101];
	int choice, k = 0, c;
	float CW ;
	system("clear");
	ctn: do
	{
		printf("Danh sach chuc nang:\n");
		printf("====================================\n");
		printf("1. Nhap thong tin kien hang\n");
		printf("2. Chi tiet kien hang bi tu choi\n");
		printf("3. Chi tiet cac kien hang hop le\n");
		printf("4. Tinh phi van chuyen\n");
		printf("5. Thoat\n\n");
		printf("Moi ban lua chon chuc nang: ");
		scanf("%d", &choice);
		printf("\n");
		 switch(choice)
		{
		   case 1: 	
		   	quantity(&n);
	    	InputParcelList(ParcelList, n);
	        printf("\n");
	        break;

	       case 2:
	       	
	        for(int i = 1; i <= n; i++)
	        {
	        	if (ErrorCode(ParcelList[i]) != 0 ) k++;
	        }
	        if (k != 0)
	        {
	        	printf("CHi tiet kien hang bi tu choi: \n");
	            printf("================================\n");
	        	printf("|%-20s|%-20s|\n", "Ma kien", "Li do tu choi");
	         	for(int i = 1; i <= n; i++)
	            {
	        	   switch( ErrorCode(ParcelList[i]) )
	       		   {
	       		    case 1:
	       			printf("|%-20s|%-20s|\n", ParcelList[i].ParcelCode, "ER1");
	       			break;
	       		    case 2:
	       			printf("|%-20s|%-20s|\n", ParcelList[i].ParcelCode, "ER2");
	       			break;
	       		    case 3:
	       			printf("|%-20s|%-20s|\n", ParcelList[i].ParcelCode, "ER3");
	       			break;
	       		    default:
	       			break;
	       		    }
	            }
	        }
	        else printf("Khong co kien hang nao xuat hien loi");			       		   
	      	printf("\n");
	      	k = 0;
	       	break;
           
           case 3:
           	
           	printf("Chi tiet cac kien hang hop le: \n");
            printf("===============================\n");
            printf("|%-20s|%-20s|%-20s|%-20s|\n", "Ma kien", "Can nang tinh phi", "Hinh thuc van chuyen", "Cuoc phi");
           	for (int i = 1; i <= n; i++)
           	{
           		if (ErrorCode(ParcelList[i]) == 0)
           		{
           		   	CW = ChargedWeight(ParcelList[i]);
           		   	c = cost(ParcelList[i]);
           			printf("|%-20s|%-20.2f|%-20s|%-20s|", ParcelList[i].ParcelCode, CW, print_tot(ParcelList[i]), PrintCost(c) );
           			printf("\n"); 
           			k++;       
           		}
           	}
           	printf("Tong so: %d\n\n", k);
           	k = 0;
           	break;
           	
           case 4:
           	int  total = 0;
           	for (int i = 1; i <= n; i++)
           	{
           		if (ErrorCode(ParcelList[i]) == 0)
           		{
           			k++;
           			total += cost(ParcelList[i]);
           		} 
           	}
           	int vat = total * 8 / 100;
           	int tt = total + vat;
           	printf("Chi phi van chuyen\n");
           	printf("=======================\n");
           	printf("So luong kien da nhan: %d\n", k);
           	printf("Tong tien cuoc: %s\n", PrintCost(total));
           	printf("VAT: %s\n", PrintCost(vat));
            printf("Tong chi phi: %s\n\n", PrintCost(tt));
            k = 0;
           	break;

           case 5:
           	char a = getchar();
            	while (a != 'Y' && a != 'n')
            	{
            		printf("Xac nhan thoat [Y/n] ? ");
                    a = getchar();
                    if (a == 'Y') break;
                    else if (a == 'n') 
                    	{ 
                    		printf("\n");
                    		goto ctn;
                    	}
                    else continue;
            	}
            
           	break;

	       	default:
	       	printf("Khong ton tai chuc nang nay. Moi nhap lai\n");
	       	break;
		}
	}
	while (choice != 5);
	return 0;
}




