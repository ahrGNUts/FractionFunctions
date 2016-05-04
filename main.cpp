#include <iostream>
#include <conio.h>
using namespace std;

int menu(int);
int add(int, int, int, int);// 1
int sub(int, int, int, int);// 2
int mul(int, int, int, int);// 3
int div(int, int, int, int);// 4
int cmp(int, int, int, int);// 5
int print(int, int, int, int, int, int, int);

int main()
{
    int selection, nu1, den1, nu2, den2;
    char slash;
    
    do {
    
    int selection = menu(selection);// calls menu
         
         
         cout << "\nEnter 2 fractions: ";
         cin >> nu1 >> slash >> den1 >> nu2 >> slash >> den2;
         while(den1 == 0 || den2 == 0)
         {
                    cout << "Invalid denominator(s)." << endl << "Enter 2 fractions: ";
                    cin >> nu1 >> slash >> den1 >> nu2 >> slash >> den2;
         } // invalid denominator checking
         
         
         if(selection == 1)
              add(nu1, den1, nu2, den2);
         else if(selection == 2)
              sub(nu1, den1, nu2, den2);
         else if(selection == 3)
              mul(nu1, den1, nu2, den2);
         else if(selection == 4)
              div(nu1, den1, nu2, den2);
         else if(selection == 5)
         {
              int compare = cmp(nu1, den1, nu2, den2);
    
              if(compare == 1)
                    cout << endl << nu1 << '/' << den1 << " is larger.\n\n";
              else if(compare == 0)
                     cout << endl << nu1 << '/' << den1 << " and " << nu2 << '/' << den2 << " are equal.\n\n";
              else if(compare == -1)
                     cout << endl << nu2 << '/' << den2 << " is larger\n\n";
         }// end if
    }while(selection != 6); // end do while
    
}// end main()

int menu(int selection)
{
    cout << "1. Add\n" << endl << "\n2. Subtract\n" << endl << "\n3. Multiply\n" << endl
         << "\n4. Divide\n" << endl << "\n5. Compare\n" << endl << "\n6. Quit\n\n";
    cin >> selection;
    while(selection <= 0 || selection >= 7)// checks validity of menu choice
    {
        cout << "\n## Enter a valid selection. ##\n" << endl << "1. Add\n" << endl << "\n2. Subtract\n" << 
        endl << "\n3. Multiply\n" << endl << "\n4. Divide\n" << endl << "\n5. Compare\n" 
        << endl << "\n6. Quit\n\n";
        cin >> selection;
    }// end while
    
    if(selection == 6)
    {    //exit(0);
        cout << "\nPress any key to continue.\n";
        _getch();
        exit(0);
    }
        return selection;
        
}// end menu()

int add(int n1, int d1, int n2, int d2)// 1
{
    int n, d, sel = 1; // sum, selection
    
    n = n1 * d2 + n2 * d1;
    d = d1 * d2;
    print(n, d, n1, d1, n2, d2, sel);

}// end add()

int sub(int n1, int d1, int n2, int d2)// 2
{
    int n, d, sel = 2;// difference, selection
    
    n = n1 * d2 - n2 * d1;
    d = d1 * d2;
    print(n, d, n1, d1, n2, d2, sel);

}// end sub()

int mul(int n1, int d1, int n2, int d2)// 3
{
    int n, d, sel = 3;// product, selection
    
    n = n1 * n2;
    d = d1 * d2;
    print(n, d, n1, d1, n2, d2, sel);

}// end mul()

int div(int n1, int d1, int n2, int d2)// 4
{
    int n, d, sel = 4;// quotient, selection
    
    n = n1 * d2;
    d = d1 * n2;
    print(n, d, n1, d1, n2, d2, sel);

}// end div()

int cmp(int n1, int d1, int n2, int d2)
{
    int size1, size2; // fraction sizes
    
    size1 = n1 * d2;// the larger size determines the larger fraction
    size2 = n2 * d1;//
    
    if(size1 > size2)
    {     
         return 1;
    }
    else if(size1 == size2)
    {     
          return 0;
    }
    else if(size1 < size2)
    {    
         return -1;
    }

}// end cmp()

int print(int n, int d, int n1, int d1, int n2, int d2, int sel)
{
    int i;
    // reduces fraction
    for(i = 2; i <= n && i <= n; i++)
    {
            if(n % i == 0 && d % i == 0)// if n and d both go into i, divide both by i
            {
                 n /=i;// division
                 d /= i;// ^^^
                 i=1;// resets loop
            }
    }

    if(sel == 1)
         cout << n1 << '/' << d1 << ' ' << '+' << ' ' << n2 << '/' << d2 << ' ' << '=' << ' ' << n << '/' << d << endl;        
    else if(sel == 2)
         cout << n1 << '/' << d1 << ' ' << '-' << ' ' << n2 << '/' << d2 << ' ' << '=' << ' ' << n << '/' << d << endl;
    else if(sel == 3)
         cout << n1 << '/' << d1 << ' ' << '*' << ' ' << n2 << '/' << d2 << ' ' << '=' << ' ' << n << '/' << d << endl;
    else
         cout << n1 << '/' << d1 << ' ' << '/' << ' ' << n2 << '/' << d2 << ' ' << '=' << ' ' << n << '/' << d << endl;

}// end print()
