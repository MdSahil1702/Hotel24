#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct userdetail
{
    char fusername[25];
    char lusername[25];
    char username[25];
    char password[25];
    int age;

} x;

struct hotel
{
    char name[50];
    char add[250];
    int price;
    float rate;
    char cont[20];
};

struct filter
{
    char name[50];
    char add[250];
    int price;
    float rate;
    char cont[20];
};


// function declaration
void gotoxy();
void delay();
void signup();
int login();
void hotels();
void showhotels();
void filter(struct hotel a[24][3], int x, int k);
void showfilters(struct filter b[9], struct hotel a[24][3], int t, int i, int g);
void payment(struct hotel a[24][3], int i, int j);
void payment1(struct filter b[9], int i);
void paymentbill(struct hotel a[24][3], int i, int j,int day,int person,int trate);
void paymentbill1(struct filter b[9], int i,int day,int person,int trate);
void linedesign();

int main()
{
    int a;
    int g = 1, j = 0;
    int k = 0;
    while (1)
    {
        /* code */

        system("cls");
        gotoxy(80, 2);
        printf("Welcome to HOTEL24");
        gotoxy(71, 3);
        printf("(Get best hotel at best price point !)");
        linedesign();
        printf("> 1.login\n");
        printf("> 2.Signup\n> Press Any Other key To Exit\n");
        scanf("%d", &a);
        int result;
        switch (a)
        {
        case 1:

            result = login();
            if (result == 5)
            {
                hotels();
            }

            break;
        case 2:
            signup();
            break;

        default:
            for (int i = 3; i >= 0; i--)
            {
                system("cls");
                gotoxy(80, 15);
                printf("Exiting in %d seconds", i);
                delay(2);
            }
            goto end;
            break;
        }

        // while ending
    }
end:
    return 0;
}

// function declaration
void signup()
{
    struct userdetail x;
    FILE *pt;
    pt = fopen("signup.txt", "w");
    system("cls");
    gotoxy(80, 2);
    printf("Creat Your Account");
    linedesign();
    printf("> Enter the First Name :  ");
    scanf("%s", &x.fusername);
    printf("> Enter the Last Name :  ");
    scanf("%s", &x.lusername);
    printf("> Enter the username :  ");
    scanf("%s", &x.username);
    printf("> Enter the password :  ");
    scanf("%s", &x.password);
    printf("> Enter the age :  ");
    scanf("%d", &x.age);
    fwrite(&x, sizeof(x), 1, pt);
    fclose(pt);
    if (pt == NULL)
    {
        printf("Try again\n");
    }
    else
    {
        system("cls");
        gotoxy(80, 16);
        printf("Your id has been created successfully\nEnter any key to continue\n");

        getch();
    }
}
int login()
{
    char username[25];
    char password[25];
    system("cls");
    gotoxy(80, 2);
    printf("Login Here");
    linedesign();
    printf("> Enter the username :  ");
    scanf("%s", username);
    printf("> Enter the password :  ");
    scanf("%s", password);
    FILE *pt;
    pt = fopen("signup.txt", "r");
    while (fread(&x, sizeof(x), 1, pt))
    {
        if (strcmp(username, x.username) == 0 && strcmp(password, x.password) == 0)
        {
            system("cls");  
            gotoxy(80, 16);
            printf("You Are Welcome\nEnter any key to continue\n");
            getch();
            return 5;
        }

        else
        {
            gotoxy(80, 16);
            printf("Either Your Username or Password is incorrect\nTry Again\n");
            printf("Enter any key to continue");
            getch();
        }
    }
}

void hotels()
{
    system("cls");
    char location[50];
    gotoxy(80, 2);
    FILE *pt = fopen("signup.txt", "r");
    fread(&x, sizeof(x), 1, pt);
    printf("Hey %s %s !", x.fusername, x.lusername);
    fclose(pt);
    linedesign();
    printf("\n\n> Enter the location :  ");
    printf("\n> Enter goback for back :  \n");
    scanf("%s", location);
    strcpy(location, strlwr(location));
    printf("%s", location);

    if (strcmp(location, "csmt") == 0 || strcmp(location, "chatrapatishivajimaharaj") == 0)
    {
        showhotels(21, 21, 1, 0);
    }

    if (strcmp(location, "masjidbunder") == 0)
    {
        showhotels(21, 21, 1, 0);
    }

    if (strcmp(location, "sandhurstroad") == 0)
    {
        showhotels(20, 20, 1, 0);
    }

    if (strcmp(location, "byculla") == 0)
    {
        showhotels(19, 19, 1, 0);
    }
    if (strcmp(location, "chinchpokli") == 0)
    {
        showhotels(18, 18, 1, 0);
    }

    if (strcmp(location, "curry road") == 0)
    {
        showhotels(17, 17, 1, 0);
    }

    if (strcmp(location, "parel") == 0)
    {
        showhotels(16, 16, 1, 0);
    }

    if (strcmp(location, "dadar") == 0)
    {
        showhotels(15, 15, 1, 0);
    }
    if (strcmp(location, "matunga") == 0)
    {
        showhotels(14, 14, 1, 0);
    }

    if (strcmp(location, "sion") == 0)
    {
        showhotels(13, 13, 1, 0);
    }

    if (strcmp(location, "kurla") == 0)
    {
        showhotels(12, 12, 1, 0);
    }
    if (strcmp(location, "vidyavihar") == 0)
    {
        showhotels(11, 11, 1, 0);
    }

    if (strcmp(location, "ghatkopar") == 0)
    {
        showhotels(10, 10, 1, 0);
    }

    if (strcmp(location, "vikroli") == 0)
    {
        showhotels(9, 9, 1, 0);
    }

    if (strcmp(location, "kanjur marg") == 0)
    {
        showhotels(8, 8, 1, 0);
    }

    if (strcmp(location, "bhandup") == 0)
    {
        showhotels(7, 7, 1, 0);
    }
    if (strcmp(location, "nahur") == 0)
    {
        showhotels(6, 6, 1, 0);
    }

    if (strcmp(location, "mulund") == 0)
    {
        showhotels(5, 5, 1, 0);
    }

    if (strcmp(location, "thane") == 0)
    {
        showhotels(4, 4, 1, 0);
    }

    if (strcmp(location, "kalwa") == 0)
    {
        showhotels(3, 3, 1, 0);
    }
    if (strcmp(location, "mumbra") == 0)
    {
        showhotels(2, 2, 1, 0);
    }
    if (strcmp(location, "diva") == 0)
    {
        showhotels(1, 1, 1, 0);
    }
    if (strcmp(location, "kopar") == 0)
    {
        showhotels(0, 0, 1, 0);
    }
    if (strcmp(location, "dombivali") == 0)
    {
        showhotels(0, 0, 1, 0);
    }

    if (strcmp(location, "goback") == 0)
    {
        system("cls");
        for (int i = 3; i >= 0; i--)
        {
            gotoxy(80, 16);
            printf("wait %d seconds", i);
            delay(2);
        }
    }

    else
    {

        for (int i = 3; i >= 0; i--)
        {
            system("cls");
            gotoxy(70, 15);
            printf("No hotels for such location please try again\n");
            gotoxy(80, 16);
            printf("wait %d seconds", i);
            delay(2);
        }

        system("cls");
        hotels();
    }
}

void showhotels(int y, int i, int g, int j)
{

    int v;
    struct hotel a[24][3];

strcpy(a[0][0].name," hotel Laxvas ");
strcpy(a[0][0].add,"RP-257, MIDC - Mhatre Pada Rd, Phase II, Dombivli East, Dombivli, Maharashtra 421204");
a[0][0].price=7000;
a[0][0].rate=5.8;
strcpy(a[0][0].cont, "2907689430");
//a[0][0].cont=2907689430;


strcpy(a[0][1].name,"Hotel Riviera Residency");
strcpy(a[0][1].add,"above Prajapati Hall, Sector 1, Dombivli West Mumbai, Maharashtra 400708");
a[0][1].price=4700;
a[0][1].rate=5.0;
strcpy(a[1][1].cont, "7958463217");
//a[0][1].cont=958463217;

strcpy(a[0][2].name,"Hotel Landmark Aura");
strcpy(a[0][2].add," MIDC Industrial Area, Dombivli, Mumbai");
a[0][2].price=2600;
a[0][2].rate=4.2;
strcpy(a[0][2].cont, "78658067823");
//a[0][2].cont=8658067823;





strcpy(a[1][0].name,"Hotel Dp Service ");
strcpy(a[1][0].add,"kopar Naka, Shilphata,Maharashtra 421204");
a[1][0].price=5799;
a[1][0].rate=4.2;
strcpy(a[1][0].cont, "7895232120");
//a[1][0].cont=7895232120;

strcpy(a[1][1].name,"hotel Couple Friendly");
strcpy(a[1][1].add,"nss road kopar mumbai");
a[1][1].price=2324;
a[1][1].rate=3.0;
strcpy(a[1][1].cont, "12414092600");
//a[1][1].cont=12414092600;

strcpy(a[1][2].name," hotel Sai Sagar");
strcpy(a[1][2].add,"R222, Raghoba road, Kopar");
a[1][2].price=17790;
a[1][2].rate=3.8;
strcpy(a[1][2].cont, "02547887230");
//a[1][2].cont=2547887230;




strcpy(a[2][0].name,"Hotel Samaira Residency");
strcpy(a[2][0].add,"3rd Floor Samaira slay commercial complex, MH SH 76, Katai Village, Nilje Gao. ");
a[2][0].price=3200;
a[2][0].rate=3.4;
strcpy(a[2][0].cont, "082917 33733");
//a[0] [0].cont=082917 33733;

strcpy(a[2][1].name,"Hotel Amantran");
strcpy(a[2][1].add,"4the Floor,Samarth Commercial Plaza, near Lodha Palava, opp. Katai Toll, Maharashtra 421201");
a[2][1].price=2800;
a[2][1].rate=3.2;
strcpy(a[2][1].cont, "090760 60555");
//a[0] [1].cont=090760 60555;

strcpy(a[2][2].name,"Hotel Stay Inn");
strcpy(a[2][2].add,"PAP R, 608, Rabale MIDC Rd, opp. SEA SAGA PVT LTD, near GAVDEVI HOTEL");
a[2][2].price=1763;
a[2][2].rate=6.7;
strcpy(a[2][2].cont, "8655772109");
//a[0] [2].cont=8655772109;



    strcpy(a[3][0].name, "flagship hotel");
    strcpy(a[3][0].add, "paper 161,near vista inn hotel,mumbra");
    a[3][0].price = 1240;
    a[3][0].rate = 2.9f;
    strcpy(a[3][0].cont, "0124768545");
    // a[3][0].contact=0124768545;

    strcpy(a[3][1].name, "hotel sai bansiresidency");
    strcpy(a[3][1].add, "plot no c105 turbhe road midc industrialarea,mumbra");
    a[3][1].price = 1050;
    a[3][1].rate = 2.9f;
    strcpy(a[3][1].cont, "0176885429");
    // a[3][1].contact=0176885429;

    strcpy(a[3][2].name, "hotel pearl residency");
    strcpy(a[3][2].add, "dahisar mori ,mumbra");
    a[3][2].price = 534;
    a[3][2].rate = 2.9f;
    strcpy(a[3][2].cont, "0898634478");
    // a[3][2].contact=0898634478;

    strcpy(a[4][0].name, "srikrishna paradise hotel");
    strcpy(a[4][0].add, "no.x1,near vitava ttc industrial area ganpati pada near vitava kalwa");
    a[4][0].price = 2380;
    a[4][0].rate = 3.9;
    strcpy(a[4][0].cont, "7466893465");
    // a[4][0].contact=7466893465;

    strcpy(a[4][1].name, "hotel riviera residency");
    strcpy(a[4][1].add, "gala no.38,near kharegaon toll naka,kalwa");
    a[4][1].price = 2318;
    a[4][1].rate = 3.9;
    strcpy(a[4][1].cont, "0983784657");
    // a[4][1].contact=0983784657;

    strcpy(a[4][2].name, "hotel time square");
    strcpy(a[4][2].add, "clock tower gcc club rd hatkesh udhog nagar kalwa");
    a[4][2].price = 3505;
    a[4][2].rate = 3.9;
    strcpy(a[4][2].cont, "0807045444");
    // a[4][2].contact=0807045444;

    strcpy(a[5][0].name, "royal park residency");
    strcpy(a[5][0].add, "belapur road next to mukund company digha naka ramu limaje nagar,thane");
    a[5][0].price = 3525;
    a[5][0].rate = 3.9;
    strcpy(a[5][0].cont, "7548955638");
    // a[5][0].contact=7548955638;

    strcpy(a[5][1].name, "hotel dheraj residency");
    strcpy(a[5][1].add, "shraddha darshan bldg,luisewadi service road next to lic,thane");
    a[5][1].price = 2679;
    a[5][1].rate = 3.3;
    strcpy(a[5][1].cont, "7478340589");
    // a[5][1].contact=7478340589;

    strcpy(a[5][2].name, "hotel capitol");
    strcpy(a[5][2].add, "near majiwala junction,majiwala petrol pump,thane");
    a[5][2].price = 4145;
    a[5][2].rate = 3.9;
    strcpy(a[5][2].cont, "8536483749");
    // a[5][2].contact=8536483749;

    strcpy(a[17][0].name, "The Lalit Mumbai");
    strcpy(a[17][0].add, "Sahar, Andheri, Andheri East, Mumbai, India, 400059");
    a[17][0].price = 8900;
    a[17][0].rate = 5.0;
    strcpy(a[17][0].cont, "0124768545");

    strcpy(a[17][1].name, "Kumkum");
    strcpy(a[17][1].add, "165, Lamington Rd, Opposite Minerva Cinema, Grant Road East, Bharat Nagar, Grant Road, Mumbai, Maharashtra 400007");
    a[17][1].price = 2100;
    a[17][1].rate = 3.9;
    strcpy(a[17][1].cont, "075060 38989");

    strcpy(a[17][2].name, "Hotel Bawa Regency");
    strcpy(a[17][2].add, "Plot No. 16, 76, Gokuldas Pasta Rd, behind Chitra Cinema, Dadar East, Dadar, Mumbai, Maharashtra 400014");
    a[17][2].price = 2464;
    a[17][2].rate = 4.0;
    strcpy(a[17][2].cont, "022 4049 8383");

    strcpy(a[16][0].name, "Hotel Karishma");
    strcpy(a[16][0].add, "Takshashila Co-op Housing Society Ltd, 5th Floor, Madhavadas Pasta Marg, Behind Chitra Cinema, Dadar East, Mumbai, Maharashtra 400014");
    a[16][0].price = 2619;
    a[16][0].rate = 3.2;
    strcpy(a[16][0].cont, "098672 97506");

    strcpy(a[16][1].name, "HSharda Lodge");
    strcpy(a[16][1].add, "Sharada Mansion, fire brigade, 188/H, Dr Baba Saheb Ambedkar Rd, opposite dadar, Dadar East, Mumbai, Maharashtra 400014");
    a[16][1].price = 1237;
    a[16][1].rate = 3.3;
    strcpy(a[16][1].cont, "022 2416 2174");

    strcpy(a[16][2].name, "Hotel City Point");
    strcpy(a[16][2].add, "Khodadad Cir, behind Imperial Mahal, Dadar East, Dadar, Mumbai, Maharashtra 400014");
    a[16][2].price = 3369;
    a[16][2].rate = 3.7;
    strcpy(a[16][2].cont, "098209 26275");

    strcpy(a[15][0].name, "Hotel HappyLand");
    strcpy(a[15][0].add, "178, 1st Floor, Kavarana Mansion, 178, 2nd Floor, Matunga West, Mumbai, Maharashtra 400016");
    a[15][0].price = 2080;
    a[15][0].rate = 2.9;
    strcpy(a[15][0].cont, "099674 42929");

    strcpy(a[15][1].name, "new shree niwas");
    strcpy(a[15][1].add, "Arunoday, Near Matunga Road Station, Mumbai, Maharashtra 400016");
    a[15][1].price = 2687;
    a[15][1].rate = 2.8;
    strcpy(a[15][1].cont, "0124 620 1463");

    strcpy(a[15][2].name, "A.M.P");
    strcpy(a[15][2].add, "522, Jogeshwari Niwas, Adenwala Rd, Matunga E, Mumbai, Maharashtra 400019");
    a[15][2].price = 3696;
    a[15][2].rate = 3.4;
    strcpy(a[15][2].cont, "084258 00001");

    strcpy(a[20][0].name, "Comfort Inn Heritage");
    strcpy(a[20][0].add, "Sant Savata Mali Marg, opp. Gloria Church, Byculla East, Byculla, Mumbai, Maharashtra 400027");
    a[20][0].price = 8218;
    a[20][0].rate = 4.0;
    strcpy(a[20][0].cont, "022 2371 4891");

    strcpy(a[20][1].name, "Hotel AlMadina Palace");
    strcpy(a[20][1].add, "Post Office, 73, Ismail Curtey Rd, near Mandvi, Marine Lines East, Jamli Mohalla, Pydhonie, Bhuleshwar, Mumbai, Maharashtra 400003");
    a[20][1].price = 2712;
    a[20][1].rate = 3.5;
    strcpy(a[20][1].cont, "099305 57877");

    strcpy(a[20][2].name, "Hotel Bombay International");
    strcpy(a[20][2].add, "Hotel Bombay International Kedy Compound Nagpada Junction, Maharashtra 400008");
    a[20][2].price = 2911;
    a[20][2].rate = 3.8;
    strcpy(a[20][2].cont, "022 2301 6607");

    strcpy(a[19][0].name, "Rajdoot Hotel");
    strcpy(a[19][0].add, "Barrister Nath Pai Marg, J.B.Road, Cotton Green West, Sewri, Mumbai, Maharashtra 400033");
    a[19][0].price = 1564;
    a[19][0].rate = 3.4;
    strcpy(a[19][0].cont, "022 2371 4444");

    strcpy(a[19][1].name, "Hotel Balwas");
    strcpy(a[19][1].add, "Grant Road East, Khetwadi, Grant Road, Mumbai, Maharashtra 400004");
    a[19][1].price = 1836;
    a[19][1].rate = 3.6;
    strcpy(a[19][1].cont, "022 2386 3613");

    strcpy(a[19][2].name, "Hotel Orient Palace");
    strcpy(a[19][2].add, "299/301, MS Ali Road, Near Shalimar Talkies, Grant Road East, Khetwadi, Grant Road, Mumbai, Maharashtra 400007");
    a[19][2].price = 2078;
    a[19][2].rate = 3.7;
    strcpy(a[19][2].cont, "0022 2380 1341");

    strcpy(a[18][0].name, "MILAN GUEST HOUSE");
    strcpy(a[18][0].add, "13th Khetwadi Back Road, near H.N Reliance Foundation Hospital, Mumbai, Maharashtra 400004");
    a[18][0].price = 1348;
    a[18][0].rate = 3.4;
    strcpy(a[18][0].cont, "022 3285 4444");

    strcpy(a[18][1].name, "Hotel Tip Top");
    strcpy(a[18][1].add, "5th floor, Lamington Building, No. 394, Lamington Rd, opp Naaz cinema, Mumbai, Maharashtra 400004");
    a[18][1].price = 1629;
    a[18][1].rate = 3.8;
    strcpy(a[18][1].cont, "022 2387 0503");

    strcpy(a[18][2].name, "Hotel Kalpana Palace");
    strcpy(a[18][2].add, "Near 181, Patthe Bapurao Marg, Navjeevan Society,Mumbai, Maharashtra 400007");
    a[18][2].price = 2460;
    a[18][2].rate = 3.7;
    strcpy(a[18][2].cont, "096194 43332");

    strcpy(a[12][0].name, "HOTEL INDIE STAYS");
    strcpy(a[12][0].add, "Next to Centrum House, Vidhyavihar, Mumbai");
    a[12][0].price = 3600;
    a[12][0].rate = 7.6;
    strcpy(a[12][0].cont, "91-22-68606860");

    strcpy(a[12][1].name, "VOILA AT NEST");
    strcpy(a[12][1].add, "Golden Mile Rd, Vidhyavihar, Mumbai");
    a[12][1].price = 4999;
    a[12][1].rate = 8.7;
    strcpy(a[12][1].cont, "7277727375");

    strcpy(a[12][2].name, "LE MERIDIAN");
    strcpy(a[12][2].add, "Miyapur Rd,Jayabheri Enclave,vidhyavihar, Mumbai");
    a[12][2].price = 8785;
    a[12][2].rate = 8.5;
    strcpy(a[12][2].cont, "91-40-42865551");

    strcpy(a[13][0].name, "HOTEL LEMON TREE");
    strcpy(a[13][0].add, "Hotel lemon tree premier, kurla, Mumbai");
    a[13][0].price = 23787;
    a[13][0].rate = 4.1;
    strcpy(a[13][0].cont, "02242764376");

    strcpy(a[13][1].name, "HOTEL GRAND HERITAGE");
    strcpy(a[13][1].add, "Lal Bahadur Shastri Rd, opp. Kanakia zillion, Kutla West, Mumbai,400070");
    a[13][1].price = 6464;
    a[13][1].rate = 4.3;
    strcpy(a[13][1].cont, "07039371786");

    strcpy(a[13][2].name, "LA HOTEL METRO");
    strcpy(a[13][2].add, "Opp kurla Garden, Behind Kurla Court, Kurla West, Mumbai-400070");
    a[13][2].price = 5990;
    a[13][2].rate = 4.3;
    strcpy(a[13][2].cont, "91-22-26500473");

strcpy(a[14][0].name, "HOTEL PEARL VIEW");
strcpy(a[14][0].add, "LGC41/2 Indra nagar, Near maharastra kanta, LBSmarg, sion east, mumbai");
a[14][0].price=2398;
a[14][0].rate=3.3;
strcpy(a[14][0].cont, "0176885429");


strcpy(a[14][1].name, "HOTEL ASHRAY INTERNATIONAL");
strcpy(a[14][1].add, "Rd no., sion, dadar, Mumbai, Maharashtra, India, 400022");
a[14][1].price=4400;
a[14][1].rate=8.0;
strcpy(a[14][1].cont, "91-40-42865551");


strcpy(a[14][2].name, "Hotel Embassy Suites");
strcpy(a[14][2].add, "Indra nagar,near sion Garden,Mumbai");
a[14][2].price= 9178;
a[14][2].rate=3.5;
strcpy(a[14][2].cont, "372996480");










    strcpy(a[11][0].name, "ascoot inn");
    strcpy(a[11][0].add, "12 shakinaka metro bmc school andheri ghatkoapr");
    a[11][0].price = 3400;
    a[11][0].rate = 3.2;
    strcpy(a[11][0].cont, "8286059654");

    strcpy(a[11][1].name, "hotel blue inn");
    strcpy(a[11][1].add, "f 35 vaibhav kailash indurstrial complex , ghatkoapr");
    a[11][1].price = 2060;
    a[11][1].rate = 2.8;
    strcpy(a[11][1].cont, "82465214831");

    strcpy(a[11][2].name, "the roa hotel");
    strcpy(a[11][2].add, "333 lbs marg ghatkopar(w),mumbai");
    a[11][2].price = 1346;
    a[11][2].rate = 6.7;
    strcpy(a[11][2].cont, "9547612304");

    strcpy(a[10][0].name, "an accor band");
    strcpy(a[10][0].add, "cst no 17 shastri road vikroli");
    a[10][0].price = 6799;
    a[10][0].rate = 4.5;
    strcpy(a[10][0].cont, "7895632104");

    strcpy(a[10][1].name, "hotel welcome");
    strcpy(a[10][1].add, "nss road aslpha vikroli");
    a[10][1].price = 1624;
    a[10][1].rate = 5.0;
    strcpy(a[10][1].cont, "12416021600");

    strcpy(a[10][2].name, "hotel greenforest");
    strcpy(a[10][2].add, "vijay nagar knakia road near police camp vikroli");
    a[10][2].price = 1172;
    a[10][2].rate = 2.8;
    strcpy(a[10][2].cont, "2547896310");

    strcpy(a[9][0].name, "hotel ulife");
    strcpy(a[9][0].add, "133 bail setan compound mahakali marol military roaa opp bharat one kanjumarg");
    a[9][0].price = 2002;
    a[9][0].rate = 3.5;
    strcpy(a[9][0].cont, "1246230160");

    strcpy(a[9][1].name, "hotel town house");
    strcpy(a[9][1].add, "1 royal palms aarey colony kanumarg");
    a[9][1].price = 1246;
    a[9][1].rate = 5.0;
    strcpy(a[9][1].cont, "958463217");

    strcpy(a[9][2].name, "capital solitare ");
    strcpy(a[9][2].add, "40 off palm beach sector 19 kanumarg");
    a[9][2].price = 1672;
    a[9][2].rate = 4.4;
    strcpy(a[9][2].cont, "78423654013");

    strcpy(a[21][0].name, "hotel Taj Mahal palace");
    strcpy(a[21][0].add, "Mumbai csmt appolo bandar,colaba,mumbai, Maharashtra,400001");
    a[21][0].price = 53336;
    a[21][0].rate = 5.9,
    strcpy(a[21][0].cont, "02266653366");

    strcpy(a[21][1].name, "oberoi hotel Mumbai");
    strcpy(a[21][1].add, "nariman point,mumbai,400021");
    a[21][1].price = 25338;
    a[21][1].rate = 5.6;
    strcpy(a[21][1].cont, "02266326245");

    strcpy(a[21][2].name, "sahara star");
    strcpy(a[21][2].add, "nahru Rd ,opp domestic airport ,navpada , ville parla ,mumbai,40009");
    a[21][2].price = 15667;
    a[21][2].rate = 5.4;
    strcpy(a[21][2].cont, "02239895000");

    strcpy(a[22][0].name, "ITC Maratha, a Luxury Collection Hotel, Mumbai");
    strcpy(a[22][0].add, "Sahar Airport road,near in international airport, Andheri East,400099,mumbai");
    a[22][0].price = 16134;
    a[22][0].rate = 5.3;
    strcpy(a[22][0].cont, "02228303030");

    strcpy(a[22][1].name, "taj Santacruz,mumbai");
    strcpy(a[22][1].add, "chatrapati shivaji intr,airport,400099,mumbai");
    a[22][1].price = 21830;
    a[22][1].rate = 5.5;
    strcpy(a[22][1].cont, "02262115211");

    strcpy(a[22][2].name, "the Lalit mumbai");
    strcpy(a[22][2].add, "Santacruz shar airport road,400059,mumbai");
    a[22][2].price = 12750;
    a[22][2].rate = 5.1;
    strcpy(a[22][2].cont, "02266992222");

    strcpy(a[23][0].name, "hotel New Silver Elite");
    strcpy(a[23][0].add, "currium house,masjid bunder west,400009,mumbai");
    a[23][0].price = 1751;
    a[23][0].rate = 3.4;
    strcpy(a[23][0].cont, "01246201463");

    strcpy(a[23][1].name, "relax guest house");
    strcpy(a[23][1].add, "Sayed mukri St,katha bazar,vadgadi,masjid bunder,400009,mumbai");
    a[23][1].price = 1557;
    a[23][1].rate = 3.2;
    strcpy(a[23][1].cont, "022952250");

    strcpy(a[23][2].name, "hotel Al makkah");
    strcpy(a[23][2].add, "Mohammad Ali road musjid bunder,400003,mumbai");
    a[23][2].price = 1001;
    a[23][2].rate = 1.3;
    strcpy(a[23][2].cont, "+917942594318");

    strcpy(a[6][0].name, "dream residency");
    strcpy(a[6][0].add, " Goregaon link.Rd opp.wockhardt hospital Fortis Sarvodaya nagar,mulund west 400080");
    a[6][0].price = 3011;
    a[6][0].rate = 3.5;
    strcpy(a[6][0].cont, "7045400094");

    strcpy(a[6][1].name, " pravasi Residency");
    strcpy(a[6][1].add, " Nsb Road opp,mulund police station,near panch rasta, mulund west");
    a[6][1].price = 2047;
    a[6][1].rate = 3.6;
    strcpy(a[6][1].cont, "02225649903");

    strcpy(a[6][2].name, "Hotel Archana Residency");
    strcpy(a[6][2].add, "R mall,big bazaar,L.B.S Marg Mulund West, Mumbai, Maharashtra 400080");
    a[6][2].price = 5214;
    a[6][2].rate = 4.1;
    strcpy(a[6][2].cont, "02221645060");

    strcpy(a[7][0].name, "The Beatle");
    strcpy(a[7][0].add, "JMJ House, Orchard Ave, Hiranandani Gardens, nahur, Mumbai, Maharashtra 400076 ");
    a[7][0].price = 7666;
    a[7][0].rate = 4.1;
    strcpy(a[7][0].cont, "02240895000");

    strcpy(a[7][1].name, "Meluha the fern ");
    strcpy(a[7][1].add, "4W96+493, Central Ave, Hiranandani Gardens, Panchkutir Ganesh Nagar, nahur, Mumbai, Maharashtra 400076");
    a[7][1].price = 12856;
    a[7][1].rate = 4.4;
    strcpy(a[7][1].cont, "022 2575 5555");

    strcpy(a[7][2].name, "Blue sky");
    strcpy(a[7][2].add, "Plot 32/33, Lal Bahadur Shastri Road, nahur West, Mumbai - 400078 (Near Sbi Bank) ");
    a[7][2].price = 2244;
    a[7][2].rate = 4.1;
    strcpy(a[7][2].cont, "01246201214");

    strcpy(a[8][0].name, "The Hill Green");
    strcpy(a[8][0].add, "Eastern Business district Ground Floor,unit no.A-21A&A21B,lal bahadur shastri Rd,Bhandup.west,mumbai.Maharashtra.400078");
    a[8][0].price = 3571;
    a[8][0].rate = 3.8;
    strcpy(a[8][0].cont, "9167363837");

    strcpy(a[8][1].name, "Royal symph");
    strcpy(a[8][1].add, "Lorven house lal bahadur shastri road opp , Magnet Mal, Bhandup west, Mumbai, Maharashtra 400078");
    a[8][1].price = 4300;
    a[8][1].rate = 3.9;
    strcpy(a[8][1].cont, "7045166888");

    strcpy(a[8][2].name, "Pride Hotel");
    strcpy(a[8][2].add, "LBS Marg,Next to Dreams Mall Bhadup,Mumbai 400078 India");
    a[8][2].price = 2240;
    a[8][2].rate = 3.5;
    strcpy(a[8][2].cont, "9372996480");

    char c;

    system("cls");
    gotoxy(80, 2);
    printf("Here the Near by hotel Listed Below");
    linedesign();

    printf("> Hotel Name :\t%s\n\n", a[i][j].name);

    printf("> Hotel Address :\t%s\n\n", a[i][j].add);

    printf("> Hotel Price :\t%d\n\n", a[i][j].price);

    printf("> Hotel rate :\t%.1f\n\n", a[i][j].rate);

    printf("> Hotel Contact No :\t%s\n\n", a[i][j].cont);
    linedesign();
    if (j >= 3)
    {
        j = 0;
        i++;
    }
    else if (j <= -1)
    {
        j = 2;
        i--;
    }

    switch (g)
    {
    case 1:
        printf("> Enter n for next\n> Enter f for filter\n> Enter s for changing the location\n> Enter p for payment\n");
        scanf("%c%c", &c, &c);

        switch (c)
        {
        case 'n':
            j++;
            g++;
            showhotels(y, i, g, j);
            break;
        case 'f':

            filter(a, y, 0);
            break;
        case 's':
            for (int i = 3; i >= 0; i--)
            {
                system("cls");
                gotoxy(80, 15);
                printf("Wait %d seconds", i);
            }
            hotels();
        case 'p':
            payment(a, i, j);
            break;
            break;
        default:
            system("cls");
            gotoxy(80, 15);
            printf("Invalid input\n");
            getch();
            showhotels(y, y, 1, 0);
            break;
        }
        break;

    case 10:
        system("cls");
        gotoxy(80, 15);
        printf("NO MORE HOTELS ");
        getch();
        showhotels(y, y, 1, 0);
        break;

    default:
        printf("> Enter n for next hotel\n> Enter b for back\n> Enter f for filter\n> Enter s for changing location\n> Enter p for payment\n");
        scanf("%c%c", &c, &c);

        switch (c)
        {
        case 'b':
            g--;
            j--;
            showhotels(y, i, g, j);
            break;

        case 'n':
            j++;
            g++;
            showhotels(y, i, g, j);
            break;

        case 'f':

            filter(a, y, 0);
            break;
        case 's':
            for (int i = 3; i >= 0; i--)
            {
                system("cls");
                gotoxy(80, 15);
                printf("Wait %d seconds", i);
                delay(2);
            }
            hotels();
            break;
        case 'p':
            payment(a, i, j);
            break;
        default:
            system("cls");
            gotoxy(80, 15);
            printf("Invalid input\n");
            getch();
            showhotels(y, y, 1, 0);
            break;
        }
    }
}

int v;

char tempname[50];
char tempadd[250];
int tempprice;
float temprate;
char tempcont[15];

void filter(struct hotel a[24][3], int x, int k)
{
    
    system("cls");
    gotoxy(80, 2);
    printf("Filter Section");
    linedesign();
    printf("> 1.low to high Price\n> 2.High to low Price\n> 3.Polularity\n");
    scanf("%d", &v);
    struct filter b[9];

    for (int i = x; i <= x + 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            strcpy(b[k].name, a[i][j].name);
            strcpy(b[k].add, a[i][j].add);
            b[k].price = a[i][j].price;
            b[k].rate = a[i][j].rate;
            strcpy(b[k].cont, a[i][j].cont);

            k++;
        }
    }

    if (v == 1)
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = i + 1; j <= 8; ++j)
            {

                if (b[i].price > b[j].price)
                {
                    strcpy(tempname, b[i].name);
                    strcpy(tempadd, b[i].add);
                    strcpy(tempcont, b[i].cont);
                    tempprice = b[i].price;
                    temprate = b[i].rate;

                    strcpy(b[i].name, b[j].name);
                    strcpy(b[i].add, b[j].add);
                    strcpy(b[i].cont, b[j].cont);
                    b[i].price = b[j].price;
                    b[i].rate = b[j].rate;

                    strcpy(b[j].name, tempname);
                    strcpy(b[j].add, tempadd);
                    strcpy(b[j].cont, tempcont);
                    b[j].price = tempprice;
                    b[j].rate = temprate;
                }
            }
        }
        showfilters(b, a, x, 0, 1);
    }
    if (v == 2)
    {

        for (int i = 0; i < 8; ++i)
        {
            for (int j = i + 1; j <= 8; ++j)
            {

                if (b[i].price < b[j].price)
                {
                    strcpy(tempname, b[i].name);
                    strcpy(tempadd, b[i].add);
                    strcpy(tempcont, b[i].cont);
                    tempprice = b[i].price;
                    temprate = b[i].rate;

                    strcpy(b[i].name, b[j].name);
                    strcpy(b[i].add, b[j].add);
                    strcpy(b[i].cont, b[j].cont);
                    b[i].price = b[j].price;
                    b[i].rate = b[j].rate;

                    strcpy(b[j].name, tempname);
                    strcpy(b[j].add, tempadd);
                    strcpy(b[j].cont, tempcont);
                    b[j].price = tempprice;
                    b[j].rate = temprate;
                }
            }
        }

        showfilters(b, a, x, 0, 1);
    }
    if (v == 3)
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = i + 1; j <= 8; ++j)
            {

                if (b[i].rate < b[j].rate)
                {
                    strcpy(tempname, b[i].name);
                    strcpy(tempadd, b[i].add);
                    strcpy(tempcont, b[i].cont);
                    tempprice = b[i].price;
                    temprate = b[i].rate;

                    strcpy(b[i].name, b[j].name);
                    strcpy(b[i].add, b[j].add);
                    strcpy(b[i].cont, b[j].cont);
                    b[i].price = b[j].price;
                    b[i].rate = b[j].rate;

                    strcpy(b[j].name, tempname);
                    strcpy(b[j].add, tempadd);
                    strcpy(b[j].cont, tempcont);
                    b[j].price = tempprice;
                    b[j].rate = temprate;
                }
            }
        }
        showfilters(b, a, x, 0, 1);
    }


    else{
        system("cls");
            gotoxy(80, 15);
            printf("Invalid input\n");
            getch();
            filter(a,x,0);
    }
}

void showfilters(struct filter b[9], struct hotel a[24][3], int t, int i, int g)
{
    char c;

    system("cls");
    gotoxy(80, 2);
    printf("Here the Near by hotel");
    linedesign();

    printf("> Hotel Name :\t%s\n\n", b[i].name);

    printf("> Hotel Address :\t%s\n\n", b[i].add);

    printf("> Hotel Price :\t%d\n\n", b[i].price);

    printf("> Hotel rate :\t%.1f\n\n", b[i].rate);

    printf("> Hotel Contact No :\t%s\n\n", b[i].cont);
    linedesign();

    switch (g)
    {
    case 1:
        printf("> Enter n for next\n> Enter p for payment\n> Enter r for remove filter\n");
        scanf("%c%c", &c, &c);

        switch (c)
        {
        case 'n':
            i++;
            g++;
            showfilters(b, a, t, i, g);
            break;
        case 'r':
            for (int i = 3; i >= 0; i--)
            {
                system("cls");
                gotoxy(80, 15);
                printf("Wait %d seconds", i);
                delay(2);
            }
            showhotels(t, t, 1, 0);
            break;
        case 'p':
            payment1(b, i);
            break;
        default:

            system("cls");
            gotoxy(80, 15);
            printf("Invalid input\n");
            getch();
            showfilters(b, a, t, 0, 1);
            break;
        }
        break;

    case 10:
        system("cls");
        gotoxy(80, 15);
        printf("no more hotels ");
        getch();
        showfilters(b, a, t, 0, 1);

        break;

    default:
        printf("> Enter n for next hotel\n> Enter b for back\n> Enter p for payment\n> Enter r for remove filter\n");
        scanf("%c%c", &c, &c);

        switch (c)
        {
        case 'b':
            g--;
            i--;
            showfilters(b, a, t, i, g);
            break;

        case 'n':
            i++;
            g++;
            showfilters(b, a, t, i, g);
            break;
        case 'r':
            for (int i = 3; i >= 0; i--)
            {
                system("cls");
                gotoxy(80, 15);
                printf("Wait %d seconds", i);
                delay(2);
            }
            showhotels(t, t, 1, 0);
            break;
        case 'p':
            payment1(b, i);
            break;
        default:
            system("cls");
            gotoxy(80, 15);
            printf("Invalid input\n");
            getch();
            showfilters(b, a, t, 0, 1);
            break;
        }
    }
}

void payment(struct hotel a[24][3], int i, int j)
{
    char upi[30];
    char id;
   

char up1[]="@paytm";
char up2[]="@upi";
char up3[]="@ybl";
char up4[]="@barodapay";
char up5[]="@axis";
char up6[]="@hdfc";
char up7[]="@pnb";
char up8[]="@icici";
char up9[]="@sbi";

char *p;
char *p1;
char *p2;
char *p3;
char *p4;
char *p5;
char *p6;
char *p7;
char *p8;
int day,person;
    system("cls");
    gotoxy(80, 2);
    printf("Please Proceed Your Payment");
    linedesign();
    printf("* %d for 1  Day stay / Person\n",a[i][j].price);
    printf("> Enter the Day You wanna stay\n");
scanf("%d",&day);
printf("> Enter The Number for Person\n");
scanf("%d",&person);
int trate=a[i][j].price*(day*person);
  printf("> Your total Amount is %d\n",trate);
    printf("> Enter your upi\n");
    scanf("%s", upi);
    p=strstr(upi,up1);
    p8=strstr(upi,up2);
    p1=strstr(upi,up3);
    p2=strstr(upi,up4);
    p3=strstr(upi,up5);
    p4=strstr(upi,up6);
    p5=strstr(upi,up7);
    p6=strstr(upi,up8);
    p7=strstr(upi,up9);
   
if(p==NULL && p1==NULL && p2==NULL && p3==NULL&&  p4==NULL && p5==NULL && p6==NULL && p7==NULL && p8==NULL)
{
        printf("\n Wrong Upi Try again\n");
        getch();
        payment(a,i,j);

    }

    else
    {
     
    
    printf("\n\n\nRequest has been sent on %s for Amount %d\nPlease accept it to continue\n", upi,trate);
    printf("\n\nEnter 'y' for accepted 'n' for rejected :  \n");
    scanf("%c", &id);
    scanf("%c", &id);
    switch (id)
    {
    case 'y':
        system("cls");
        gotoxy(80, 16);
        printf("Your Hotel has been successfully Booked\n");
        printf("Enter any key to continue\n");
        getch();
        paymentbill(a, i, j,day,person,trate);
        break;

    case 'n':
        system("cls");
        gotoxy(80, 16);
        printf("Booking Has Been Cancelled\n");
        getch();
        hotels();
        break;

    default:

        break;
    }
    }
    
}

void payment1(struct filter b[9], int i)
{
    char upi[30];
    char id;
   
    

char up1[]="@paytm";
char up2[]="@upi";
char up3[]="@ybl";
char up4[]="@barodapay";
char up5[]="@axis";
char up6[]="@hdfc";
char up7[]="@pnb";
char up8[]="@icici";
char up9[]="@sbi";

char *p;
char *p1;
char *p2;
char *p3;
char *p4;
char *p5;
char *p6;
char *p7;
char *p8;

    system("cls");
    gotoxy(80, 2);
    printf("Please Proceed Your Payment");
    linedesign();
    int person,day,trate;
     printf("* %d for 1  Day stay / Person\n",b[i].price);
    printf("> Enter the Day You wanna stay\n");
scanf("%d",&day);
printf("> Enter The Number for Person\n");
scanf("%d",&person);
trate=b[i].price*(day*person);
  printf("> Your total Amount is %d\n",trate);
    printf("> Enter your upi\n");
    scanf("%s", upi);
    p=strstr(upi,up1);
    p8=strstr(upi,up2);
    p1=strstr(upi,up3);
    p2=strstr(upi,up4);
    p3=strstr(upi,up5);
    p4=strstr(upi,up6);
    p5=strstr(upi,up7);
    p6=strstr(upi,up8);
    p7=strstr(upi,up9);

    if(p==NULL && p1==NULL && p2==NULL && p3==NULL&&  p4==NULL && p5==NULL && p6==NULL && p7==NULL && p8==NULL)
{
        printf("\n Wrong Upi Try again\n");
        getch();
        payment1(b,i);

    }

   else 
   {

    printf("\n\n\nRequest has been sent on %s\nPlease accept it to continue\n", upi);
    printf("\n\nEnter 'y' for accepted 'n' for rejected :  \n");
    scanf("%c", &id);
    scanf("%c", &id);
    switch (id)
    {
    case 'y':
        system("cls");
        gotoxy(80, 16);
        printf("Your Hotel has been successfully Booked\n");
        printf("Enter any key to continue\n");
        getch();
        paymentbill1(b, i,day,person,trate);
        break;

    case 'n':
        system("cls");
        gotoxy(80, 16);
        printf("Booking Has Been Cancelled\n");
        getch();
        hotels();
        break;

    default:

        break;
    }
}
    
}

void paymentbill(struct hotel a[24][3], int i, int j,int day,int person,int trate)

{
    system("cls");
    gotoxy(80, 2);
    printf("ORDER INFORMATION !");
    linedesign();
    printf("User information\n\n");

    FILE *pt = fopen("signup.txt", "r");
    fread(&x, sizeof(x), 1, pt);
    printf("> First Name :  %s\n", x.fusername);
    printf("> Last Name :  %s\n", x.lusername);
    printf("> Age :  %d", x.age);
    linedesign();

    fclose(pt);
    printf("Hotel information\n\n");

    printf("> Name :  %s\n", a[i][j].name);
    printf("> Address : %s\n", a[i][j].add);
    printf("> Contact : %s\n", a[i][j].cont);
    printf("> Persons : %d\n", person);
    printf("> Days to stay : %d\n", day);
    printf("> Total Price : %d\n", trate);
    printf("> Rate : %.1f", a[i][j].rate);
    linedesign();
    printf("Rules & Regulation\n\n");
    printf("> 1.Please present your ID card, Passport or Temporary Residence Card upon Check-in.\n> 2.Mention your policy for Pets ( allowed or not- allowed ) / (Allow us to make separate arrangements\n> 3.Using photographs and video's taken in the hotel for commercial or public purposes is illegal.\n");
    printf("\nEnter Any Key to continue\n");
    getch();
    for (int k = 3; k >= 0; k--)
    {
        system("cls");
        gotoxy(80, 16);
        printf("Wait %d sec", k);
        delay(2);
    }
    hotels();
}

void paymentbill1(struct filter b[9], int i,int day,int person,int trate)

{
    system("cls");
    gotoxy(80, 2);
    printf("ORDER INFORMATION !");
    linedesign();
    printf("User information\n\n");
    FILE *pt = fopen("signup.txt", "rb");
    fread(&x, sizeof(x), 1, pt);
    printf("First Name :  %s\n", x.fusername);
    printf("Last Name :  %s\n", x.lusername);
    printf("Age :  %d", x.age);
    linedesign();
    fclose(pt);
    printf("Hotel information\n\n");
    printf("> Name :  %s\n", b[i].name);
    printf("> Address : %s\n", b[i].add);
    printf("> Contact : %s\n", b[i].cont);
    printf("> Persons : %d\n", person);
    printf("> Days to stay : %d\n", day);
    printf("> Total Price : %d\n", trate);
    printf("> Rate : %.1f", b[i].rate);
    linedesign();
    printf("Rules & Regulation\n\n");
    printf("1.Please present your ID card, Passport or Temporary Residence Card upon Check-in.\n2.Mention your policy for Pets ( allowed or not- allowed ) / (Allow us to make separate arrangements\n3.Using photographs and video's taken in the hotel for commercial or public purposes is illegal.\n");
    printf("\nEnter Any Key to continue\n");
    getch();
    for (int k = 3; k >= 0; k--)
    {
        system("cls");
        gotoxy(80, 16);
        printf("Wait %d sec", k);
        delay(2);
    }
    hotels();
}

void linedesign()
{
    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void delay(int a)
{
    int time, add, i;
    time = a * 100000000;

    for (i = 0; i < time; i++)
    {
        add *= i;
        add++; // add=1
        add++; // add=2
    }
}