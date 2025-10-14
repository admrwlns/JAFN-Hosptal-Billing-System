#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function prototypes
int login();
int patientData(char[][30], int[], int[], int[], int[], int[], int[], int[]);
void displayMenu();
void invalidInput();
float calculation(float[], float[], float[], float[], float[], int);

//i and n (global variable) used as patients additional value and update
int i = 0;
int n = 0;

//pricing for patients
const float SR = 120.00;
const float MBR = 75.00;
const float COD = 7.50;
const float MD = 4.90;
const float CZ = 10.00;
const float NCZ = 15.00;
const float GMN = 8.50;
const float PS = 7.00;
const float PRVS = 10.00;
const float SG = 200.00;
const float MC = 45.50;

int main() 
{
    char name[100][30] = {""};
    int age[100], type[100], catagory[100], employment[100], ward[100], time[100], treatment[100], exit, choose, i, n, successful;
    float priceBilling, priceCategory[100]={0}, priceEmployment[100]={0}, priceWard[100]={0}, priceTime[100]={0}, priceTreatment[100]={0};


	successful = login(); //credentials login function call
    

    printf("\t--------- Welcome to JAFN Hospital Billing Service ---------\n");

	displayMenu(); //price menu function call

	do 
	{
    n = patientData(name, age, type, catagory, employment, ward, time, treatment); //patient data input function call

	//looping to display patient list (code number and name) using array
	do
	{
		printf("\nPatient Code\t\tPatient Name\n");
	
		for (i = 0; i < n; i++)
		{
    		if (name[i][0] == '\0')
        	break;
    		printf("%d\t\t\t%s\n", i + 1, name[i]);
		}

		//enter patient code to see the patient's bill
    	printf("\nEnter patient code number: ");
    	scanf("%d", &i);
    
    	if (i<1 || i>n)
    	invalidInput(); //error message function call
    	
	} while (i < 1 || i > n);

	//display bill and set pricing based on patient code entered
    i--;
    printf("\nPatient code [%d] billing:", i + 1); 
    
	printf("\nName: %s", name[i]);
    
	printf("\nAge: %d", age[i]);
    
	printf("\nType: ");
    if (type[i] == 1)
    {
        printf("Inpatient");
	}
    if (type[i] == 2)
    {
        printf("Outpatient");
    }
    
	printf("\nCatagory: ");
    if (catagory[i] == 1)
    {
        printf("Citizens");
        priceCategory[i] = CZ; 
    }
    if (catagory[i] == 2)
    {
        printf("Non-citizens");
        priceCategory[i] = NCZ;
    }
    
	printf("\nEmployment: ");
    if (employment[i] == 1)
    {
        printf("Government services");
        priceEmployment[i] = GMN;
    }
    if (employment[i] == 2)
    {
        printf("Pensioners");
        priceEmployment[i] = PS;
    }
    if (employment[i] == 3)
    {
        printf("Private sectors");
        priceEmployment[i] = PRVS;
    }
    if (type[i] == 1)
	{
        printf("\nWard type: ");
        if (ward[i] == 1)
        {
            printf("Single room");
            priceWard[i] = SR;
        }
        if (ward[i] == 2)
        {
            printf("Multi-bedded room");
            priceWard[i] = MBR;
        }
    }
	if (type[i] == 2)
	{
		printf("\nConsultation time: ");
		if(time[i] == 1)
		{
			printf("7:01 am - 10:59 pm");
			priceTime[i] = COD;
		}
		if(time[i] == 2)
		{
			printf("11:00 pm - 7:00 am");
			priceTime[i] = COD + MD;
		}
	}
    
	printf("\nTreatment: ");
    if (treatment[i] == 1)
    {
        printf("Medical");
        priceTreatment[i] = MC;
    }
    if (treatment[i] == 2)
    {
        printf("Surgery");
        priceTreatment[i] = SG;
    }
	
	priceBilling = calculation(priceCategory, priceEmployment, priceWard, priceTime, priceTreatment, i); //bill calculation function call
	
	//decision to choose between exiting or going back to menu
	do
	{
	printf("\n\nBack, Press 1\nTo exit, press 2: ");
    scanf("%d", &exit);
    if(exit<=0 || exit>2)
    {
    	invalidInput(); //error message function call
	}
	}while(exit<=0 || exit>2);
    
	
	}while(exit==1);
	
	return 0;
}

//credentials login function
int login() 
{
	int successful;
    char staffID[20];
    char password[20];

	//requires hospital staff to enter staff ID and password
	do
	{
    printf("Enter staff ID: "); // Staff ID: 12345
    scanf("%s", staffID);

    printf("Enter password: "); // Password : 54321
    scanf("%s", password);

    // Simple authentication check
    if (strcmp(staffID, "12345") == 0 && strcmp(password, "54321") == 0) 
	{
        printf("Login successful.\n");
        system("cls");
 		return successful; // Return for successful login
    } 
	
	else 
	{
        invalidInput(); //error message function call
    }
	} while(strcmp(staffID, "12345") != 0 && strcmp(password, "54321") != 0);
}

//function for displaying menu  
void displayMenu()
{
	printf("\n -------------------------------------\t    ----------------------------------------\n");
	printf("|      Inpatient      \t|  Price(RM)  |    |         Outpatient       |  Price(RM)  |\n");
	printf("|-----------------------|-------------| or |--------------------------|-------------|  \n");
	printf("|     Single Room     \t|    %.2f   |    |  Consultation of Doctor  |    %.2f     | \n", SR, COD);
	printf("|  Multi-bedded Room  \t|    %.2f    |    | + Midnight (11PM to 7AM) |   + %.2f    |\n", MBR, MD);
	printf(" -------------------------------------      ----------------------------------------\n");
	printf("\nINPATIENT are patient who are admitted overnight, OUTPATIENT are patients who are not hospitalized overnight\n\n");
	printf("\t\t -------------------------------------\n");
	printf("\t\t|   Patient Category   \t|  Price(RM)  |\n");
	printf("\t\t|-----------------------|-------------|\n");
	printf("\t\t|       Citizens       \t|    %.2f    |\n", CZ);
	printf("\t\t|     Non-citizens     \t|    %.2f    |\n", NCZ);
	printf("\t\t -------------------------------------\n");
	printf("\t\t -------------------------------------\n");
	printf("\t\t|  Patient Employement\t|  Price(RM)  |\n");
	printf("\t\t|-----------------------|-------------|\n");
	printf("\t\t|  Government Servants\t|    %.2f     |\n", GMN);
	printf("\t\t|  Pensioners         \t|    %.2f     |\n", PS);
	printf("\t\t|  Private Sectors    \t|    %.2f    |\n", PRVS);
	printf("\t\t -------------------------------------\n");
	printf("\t\t -------------------------------------\n");
	printf("\t\t|    Treatment Type    \t|  Price(RM)  |\n");
	printf("\t\t|-----------------------|-------------|\n");
	printf("\t\t|       Surgical       \t|   %.2f    |\n", SG);
	printf("\t\t|       Medical        \t|   %.2f     |\n", MC);
	printf("\t\t -------------------------------------\n");

}

//Input Patient's Data Function
int patientData(char name[][30], int age[], int type[], int catagory[], int employment[], int ward[], int time[], int treatment[]) 
{
    int choose;
    
    while (i <= n) 
	{
		do {

		//decision to choose between adding patient and continue to billing
        printf("\n\nWould you like to add a patient?, press [1] ");
        
        if(n>0)
        {
		printf("\nWould you like to proceed to billing?, press [2]: ");
		}
        scanf("%d", &choose);

        if (choose == 1) //Adding A Patient
        n++; 
        
		if(n>0)
		{ 
        	if (choose == 2) //continue to billing
        	return n; 
    	}
    	
        if (choose<1 || choose>2)
        {
        	invalidInput(); //error message function call (if invalid)
        }
		
     } while(choose<=0 || choose>1);

        printf("\nPatient code [%d]", i + 1); //display patient code number
        printf("\n\nPlease fill in the details below,");
        
		printf("\n\nEnter patient's name: "); //Patient's Name
        scanf(" %[^\n]s", name[i]);
	 	
	 	do
	 	{
		printf("Enter patient's age: "); //Patient's Age
		scanf("%d", &age[i]);
		if(age[i]<=0)
 		{
 			invalidInput();
		}
		} while(age[i]<=0);
        
		do
		{
		printf("\nPatient type:\nInpatient, press [1]\nOutpatient, press [2]: "); //Choosing the type of patient
		scanf("%d", &type[i]);
		if(type[i]<=0 || type[i]>2)
		{
			invalidInput();
		}
		} while(type[i]<=0 || type[i]>2);
  	
  		do
  		{
	  	printf("\nPatient category:\nCitizens, press [1]\nNon-citizens, press [2]: "); //Choosing the category of patient
		scanf("%d", &catagory[i]);
		if(catagory[i]<=0 || catagory[i]>2)
		{
			invalidInput();
		}
		} while(catagory[i]<=0 || catagory[i]>2);
		
		do
		{
 		printf("\nPatient employment:\nGovernment servants, press [1]\nPensioners, press [2]\nPrivate sectors, press [3]: "); //Choosing the patient's employment
 		scanf("%d", &employment[i]);
 		if(employment[i]<=0 || employment[i]>3)
		{
			invalidInput();
		}
		} while(employment[i]<=0 || employment[i]>3);
		
        if (type[i] == 1) 
		{
			do
			{
            printf("\nWard type for Inpatients:\nSingle room, press [1]\nMulti-bedded room, press [2]: "); //Choosing the patient's room
            scanf("%d", &ward[i]);
 			if(ward[i]<=0 || ward[i]>2)        
			{
				invalidInput();
			}
			} while(ward[i]<=0 || ward[i]>2);    
        }
        
        if (type[i] == 2)
        {
        	do
        	{
        	printf("\nTime of appointment:\n7:01 am - 10:59 pm, press [1]\n11:00 pm - 7:00 am, press [2]: ");//Setting the appointment's time
        	scanf("%d", &time[i]);
			if (time[i]<=0 || time[i]>2)
			{
				invalidInput();
			}
			} while(time[i]<=0 || time[i]>2);
		}
		
		do
		{
		printf("\nPatient treatment:\nMedical, press [1]\nSurgery, press [2]: "); //Choosing the type of treatment
		scanf("%d", &treatment[i]);
		if (treatment[i]<=0 || treatment[i]>2)
		{
			invalidInput();
		}
		} while (treatment[i]<=0 || treatment[i]>2);
        
        i++; //update patient
    }
}

//calculation for price billing function
float calculation(float priceCategory[], float priceEmployment[], float priceWard[], float priceTime[], float priceTreatment[], int i)
{
	float priceBilling=0.00;
	
	priceBilling = priceCategory[i] + priceEmployment[i] + priceWard[i] + priceTime[i] + priceTreatment[i];
	printf("\n\nPrice Billing: RM%.2f\n", priceBilling); //displays total price for the patient choosed in the bill
	return priceBilling;
}

//display error message for invalid input function
 void invalidInput()
 {
 	printf("\nPlease re-enter a valid input\n");
 }
