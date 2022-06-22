//Project Owner: Dilshan Oshada (SL_Drago)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

//Global Veriables
int choice=0,N;
char input;
int records=0;
int record2=0;
int record3=0;
int record4=0;

//Structure of vehicle details
struct vehicle{
    char RN [15]; //Registration No.
    char CON [15]; //Brand New or Recondition
    char MOD [20]; //Vehicle Model
    int year; //Vehicle Born year
    char color [20]; //Vehicle Color
    char CH [30]; //Chassis NO
    char EN [30]; //Engine No.
};
//Structure of Owner details
struct owner{
    char RN [15]; //Registration No.
    char ID [15]; //ID Number
    char name [50]; //Owners Name
    char address [50]; //Address of the Owner
};
//Structure of Service Details
struct service{
    char RN [15]; //Registration No.
    char SDate [15]; //Service Data
    char SDetail[500]; //Service Details
    int ODM; //Odometer Reading
};
//Structure of Accident details
struct accident{
    char RN [15]; //Registration No.
    char AccDate [15]; //Accident date
    char AccLoc [50]; //Accident Location
    char damage [100]; //damage taken to the Vehicle
};

    struct vehicle v[100];
    struct owner o[100];
    struct service s[100];
    struct accident a[100];

//delay function to add a delay between the code using seconds
void delay (int number_of_sec){
    int milli_sec = 1000 * number_of_sec;
    clock_t start_time = clock();
    while (clock() < start_time + milli_sec);
}

//Logo printing
void printLogo(){
    printf("\t*******************************************************\n");
    printf("\t** #   # ### #  # ### ### #   ###    ###   #   # #   **\n");
    printf("\t**  # #  ##  ####  #  #   #   ##     ##   ###   #    **\n");
    printf("\t**   #   ### #  # ### ### ### ###    #   #   # # #   **\n");
    printf("\t*******************************************************\n");
}

//Starting function user selecting
void start(){
    printLogo();
    printf("\n\nChoose one:\n\t1) Customer\n\t2) Service Center\n\t3) Exit\n\n");
    scanf("%d",&choice);
    printf("\n");
}

//Customer side menu
void customer_menu(){
    printf("Loading");
    for(int i=0; i<3; i++){
            printf(".");
            delay(1);
    }
    system("cls");
    choice=0;
    printLogo();
    delay(1);
    printf("\n\nWelcome to #VEHICALE FAX SL# Choose your Request:: \n\n");
    printf("\t1] Get Vehicle Report.\n\t2] Get Service Records.\n\t3] Back.\n\t4] Exit.\n\n");
    scanf("%d",&choice);
    printf("\n");
}

//Service center side menu
void service_menu(){
    printf("Loading");
    for(int i=0; i<3; i++){
            printf(".");
            delay(1);
    }
    system("cls");
    choice=0;
    printLogo();
    delay(1);
    printf("\n\nWelcome to #VEHICALE FAX SL# Choose your Request:: \n\n");
    printf("\t1] Add a Vehicle.\n\t2] Remove a Vehicle.\n\t3] Add a Ownership.\n\t4] Add a Service Record.\n\t5] Accident Details.\n\t6] Back.\n\t7] Exit.\n\n");
    scanf("%d",&choice);
    printf("\n");
}

//Full function for case 1 to achieve a callback if enter a input wrong
void case1func(){
    customer_menu();
    if (choice == 1){
        get_vehicle_report();
    }
    else if (choice == 2){
        get_service_records();
    }
    else if (choice == 3){
        delay(2);
        system("cls");
        main();           //calling back main function
    }
    else if (choice == 4){
        exit(0);
                }
    else {
        printf("Invalid Input");
        for(int i=0; i<5; i++){
            printf(".");
            delay(1);
        }
        case1func();
    }
}

//Full function for case 2 to achieve a callback if enter a input wrong
void case2func(){
        service_menu();
        if (choice == 1){
            get_vehicle_details ();
        }
        else if (choice == 2){
            removeRecords();
        }
        else if (choice == 3){
            get_ownership_details ();
        }
        else if (choice == 4){
            get_service_details ();
        }
        else if (choice == 5){
            get_accident_details ();
        }
        else if (choice == 6){
            delay(2);
            system("cls");
            main();         //calling back main function
        }
        else if (choice == 7){
            exit(0);
        }
        else {
            printf("Invalid Input");
                for(int i=0; i<5; i++){
                    printf(".");
                    delay(1);
                }
            case2func();
        }
}

//Function to get vehicle details
void get_vehicle_details (){
    system("cls");
    printLogo();
    delay(1);

            printf("\n\nEnter Vehicle Details::\n\n");
            fflush(stdin);
            printf("1] Registration No. :");
            scanf("%[^\n]s",v[records].RN);
            fflush(stdin);
            printf("2] Vehicle Condition :");
            scanf("%[^\n]s",v[records].CON);
            fflush(stdin);
            printf("3] Vehicle Model :");
            scanf("%[^\n]s",v[records].MOD);
            printf("4] Manufacture Year :");
            scanf("%d",&v[records].year);
            fflush(stdin);
            printf("5] Vehicle Color :");
            scanf("%[^\n]s",v[records].color);
            fflush(stdin);
            printf("6] Vehicle Chassis No. :");
            scanf("%[^\n]s",v[records].CH);
            fflush(stdin);
            printf("7] Vehicle Engine No. :");
            scanf("%[^\n]s",v[records].EN);
    records++;

    fflush(stdin);
    printf("\n\nDo you want to enter a new Entry?[Y/N] ::");
    scanf("%c",&input);
    if(input == 'y' || input == 'Y'){
        get_vehicle_details();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case2func();
            }else{
                exit(0);
            }
    }
}

//Function to get Ownership Details
void get_ownership_details (){
    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0;
    int i;
            printf("\n\nEnter Ownership Details::\n\n");
            fflush(stdin);
            printf("1] Registration No. :");
            scanf("%[^\n]s",rno);
            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    printf("\n\nVehicle Registration Number:\t%s\nVehicle Condition:\t\t%s\nVehicle Model:\t\t\t%s\nManufacture Year:\t\t%d\nVehicle Color:\t\t\t%s\nChassis Number:\t\t\t%s\nEngine Number:\t\t\t%s\n\n"
                           ,v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                    strcpy(o[record2].RN,rno);
                    fflush(stdin);
                    printf("2] ID Number :");
                    scanf("%[^\n]s",o[record2].ID);
                    fflush(stdin);
                    printf("3] Full Name (capital) :");
                    scanf("%[^\n]s",o[record2].name);
                    fflush(stdin);
                    printf("4] Address (capital) :");
                    scanf("%[^\n]s",o[record2].address);
                    record2++;
                }}
            if(found==0){
                    printf("\nRecord Not Found\n");
                }
    fflush(stdin);
    printf("\n\nDo you want to enter a new Entry?[Y/N] ::");
    scanf("%c",&input);
    if(input == 'y' || input == 'Y'){
        get_ownership_details ();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case2func();
            }else{
                exit(0);
            }
    }
}

//Function to get service details
void get_service_details (){
    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0;
    int i;
            printf("\n\nEnter Service Details::\n\n");
            fflush(stdin);
            printf("1] Registration No. :");
            scanf("%[^\n]s",rno);
            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    printf("\n\nVehicle Registration Number:\t%s\nVehicle Condition:\t\t%s\nVehicle Model:\t\t\t%s\nManufacture Year:\t\t%d\nVehicle Color:\t\t\t%s\nChassis Number:\t\t\t%s\nEngine Number:\t\t\t%s\n\n"
                           ,v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                    strcpy(s[record3].RN,rno);
                    fflush(stdin);
                    printf("2] Service Date :");
                    scanf("%[^\n]s",s[record3].SDate);
                    fflush(stdin);
                    printf("3] Service Details :");
                    scanf("%[^\n]s",s[record3].SDetail);
                    printf("4] Odometer Reading :");
                    scanf("%d",&s[record3].ODM);
                    record3++;
                }}
            if(found==0){
                    printf("\nRecord Not Found\n");
                }
    fflush(stdin);
    printf("\n\nDo you want to enter a new Entry?[Y/N] ::");
    scanf("%c",&input);
    if(input == 'y' || input == 'Y'){
        get_service_details ();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case2func();
            }else{
                exit(0);
            }
    }
}

//Function to get Accident details
void get_accident_details (){
    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0;
    int i;
            printf("\n\nEnter Accident Details::\n\n");
            fflush(stdin);
            printf("1] Registration No. :");
            scanf("%[^\n]s",rno);
            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    printf("\n\nVehicle Registration Number:\t%s\nVehicle Condition:\t\t%s\nVehicle Model:\t\t\t%s\nManufacture Year:\t\t%d\nVehicle Color:\t\t\t%s\nChassis Number:\t\t\t%s\nEngine Number:\t\t\t%s\n\n"
                           ,v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                    strcpy(a[record4].RN,rno);
                    fflush(stdin);
                    printf("2] Accident Date :");
                    scanf("%[^\n]s",a[record4].AccDate);
                    fflush(stdin);
                    printf("3] Accident Location :");
                    scanf("%[^\n]s",a[record4].AccLoc);
                    fflush(stdin);
                    printf("4] Damage to the Vehicle :");
                    scanf("%[^\n]s",a[record4].damage);
                    fflush(stdin);
                    record4++;
                }}
            if(found==0){
                    printf("\nRecord Not Found\n");
                }
    fflush(stdin);
    printf("\n\nDo you want to enter a new Entry?[Y/N] ::");
    scanf("%c",&input);
    if(input == 'y' || input == 'Y'){
        get_accident_details ();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case2func();
            }else{
                exit(0);
            }
    }
}

//Function to Remove Records
void removeRecords(){
        static const struct vehicle EmptyStruct1;
        static const struct owner EmptyStruct2;
        static const struct service EmptyStruct3;
        static const struct accident EmptyStruct4;

    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0;
    int i,j,k,l;
            printf("\n\nFind the Vehicle You Want to Remove::\n\n");
            fflush(stdin);
            printf("1] Registration No. :");
            scanf("%[^\n]s",rno);
            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    printf("\n\n%s %s %s %d %s %s %s\n\n",v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                        fflush(stdin);
                    printf("\n Are You Sure?[Y/N] ::");
                    scanf("%c",&input);
                    if(input == 'y' || input == 'Y'){
                    v[i]=EmptyStruct1;
                    for (j=0; j<=record2; j++){
                        if(strcmp(o[j].RN,rno)==0){
                            o[j]=EmptyStruct2;
                            }
                    }
                    for (k=0; k<=record3; k++){
                        if(strcmp(s[k].RN,rno)==0){
                            s[k]=EmptyStruct3;
                        }
                    }
                    for (l=0; l<=record4; l++){
                        if(strcmp(a[l].RN,rno)==0){
                            a[l]=EmptyStruct4;
                        }
                    }
                    delay(1);
                    printf("\n\n\xB2\xB2Vehicle Remove from System Successful ....");
                }}
            }
            if(found==0){
                    printf("\n\xB2\xB2Vehicle Record Not Found ....\n");
            }
            fflush(stdin);
    printf("\n\nDo you want to Remove another Record?[Y/N] ::");
    scanf("%c",&input);

    if(input == 'y' || input == 'Y'){
        removeRecords ();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case2func();
            }else{
                exit(0);
            }
    }
}

//Function to get full vehicle Report
void get_vehicle_report(){
    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0,owncount=0,SerCount=0,AccCount=0,acc=0,serv=0,Own=0;
    int i,j,k,l;
            printf("\n\nGet Your Vehicle Report ::\n\n");
            fflush(stdin);
            printf("Vehicle Registration No. :");
            scanf("%[^\n]s",rno);

            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    system("cls");
                    printLogo();
                    delay(1);
                    printf("\n\t\t\xB2\xB2\xB2\xB2VEHICLE REPORT\xB2\xB2\xB2\xB2\n");
                    printf("\n\nVehicle Registration Number:\t%s\nVehicle Condition:\t\t%s\nVehicle Model:\t\t\t%s\nManufacture Year:\t\t%d\nVehicle Color:\t\t\t%s\nChassis Number:\t\t\t%s\nEngine Number:\t\t\t%s\n\n"
                           ,v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                    printf("\nOwner Details ::\n\n");
                    for (i=0; i<=record2; i++){
                        if(strcmp(o[i].RN,rno)==0){
                            owncount++;
                            printf("\xB2%d st Owner:\n",owncount);
                            printf("ID:\t\t%s\nFull Name:\t%s\nAddress:\t%s\n\n",o[i].ID,o[i].name,o[i].address);
                            Own=1;
                            }
                    }
                    if(Own==0){
                    printf("\n\xB2No Owner Record Found...\n");
                    }
                    printf("\nService Details ::\n");
                    for (i=0; i<=record3; i++){
                        if(strcmp(s[i].RN,rno)==0){
                            serv=1;
                            SerCount++;
                            printf("\n\xB2%d st Service:\n",SerCount);
                            printf("Service Date:\t\t%s\nService Details:\t%s\nOdometer Reading:\t%d\n",s[i].SDate,s[i].SDetail,s[i].ODM);
                        }
                    }
                    if(serv==0){
                    printf("\n\xB2No Service Record Found...\n");
                    }
                    printf("\nAccident Details ::\n");
                    for (i=0; i<=record4; i++){
                        if(strcmp(a[i].RN,rno)==0){
                            acc=1;
                            AccCount++;
                            printf("\n\xB2%d st Accident:\n",AccCount);
                            printf("Accident Date:\t\t\t%s\nAccident Location:\t\t%s\nDamage From the Accident:\t%s\n",a[i].AccDate,a[i].AccLoc,a[i].damage);
                        }
                    }
                    if(acc==0){
                    printf("\n\xB2No Accident Record Found...\n");
                    }
                    delay(1);
                }
            }

            if(found==0){
                    printf("\n\xB2Vehicle Record Not Found ....\n");
            }
            fflush(stdin);
    printf("\n\nDo you want to Get another Report?[Y/N] ::");
    scanf("%c",&input);

    if(input == 'y' || input == 'Y'){
        get_vehicle_report ();
    }
    else{
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case1func();
            }else{
                exit(0);
            }
    }
}

//Function to get service records for a vehicle
void get_service_records(){
    system("cls");
    printLogo();
    delay(1);
    char rno [15];
    int found=0,SerCount=0,serv=0;
    int i;
            printf("\n\n\xB2\xB2 Get Your Service Record::\n\n");
            fflush(stdin);
            printf("Vehicle Registration No. :");
            scanf("%[^\n]s",rno);
            for (i=0; i<=records; i++){
                if(strcmp(v[i].RN,rno)==0){
                    found=1;
                    system("cls");
                    printLogo();
                    delay(1);
                    printf("\n\t\t\xB2\xB2\xB2\xB2SERVICE RECORD\xB2\xB2\xB2\xB2\n");
                    printf("\n\nVehicle Registration Number:\t%s\nVehicle Condition:\t\t%s\nVehicle Model:\t\t\t%s\nManufacture Year:\t\t%d\nVehicle Color:\t\t\t%s\nChassis Number:\t\t\t%s\nEngine Number:\t\t\t%s\n\n"
                           ,v[i].RN,v[i].CON,v[i].MOD,v[i].year,v[i].color,v[i].CH,v[i].EN);
                    printf("Services Have Done::\n\n");
                    for (i=0; i<=record3; i++){
                        if(strcmp(s[i].RN,rno)==0){
                            serv=1;
                            SerCount++;
                            printf("\n\xB2%d st Service:\n",SerCount);
                            printf("Service Date:\t\t%s\nService Details:\t%s\nOdometer Reading:\t%d\n",s[i].SDate,s[i].SDetail,s[i].ODM);
                        }
                    }
                }
            }
            if(serv==0){
                    printf("\n\xB2No Service Record Found...\n");
            }
            if(found==0){
                    printf("\n\xB2Vehicle Not Found\n");
            }
    fflush(stdin);
    printf("\n\nDo you want to Get a new Service Report?[Y/N] ::");
    scanf("%c",&input);
    if(input == 'y' || input == 'Y'){
        get_service_records ();
    }
    else{
            fflush(stdin);
        printf("\n1] Back.\n2] Exit.\n\n");
        scanf("%d",&choice);
            if(choice==1){
                case1func();
            }else{
                exit(0);
            }
    }
}


int main()
{
    start();
    switch (choice){
    case 1:
        case1func();
        break;
    case 2:
        case2func();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Invalid Input");
        for(int i=0; i<5; i++){
            printf(".");
            delay(1);
        }
        system("cls");
        main();
    }
    return 0;
}
