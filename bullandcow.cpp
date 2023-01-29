#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    srand(time(NULL));
    rand();
    setlocale(LC_ALL, "Ukr");
    int rand_numb, num;
    int arr_rand_system[4] = {}, arr_inputs_sign[4] = {};
    int arr_count, count_cow, count_ox, count, attempt_num;
    bool continue_ = true;
    char n;

    cout << "Це гра \"Бики і корови\"\n";

    
    while (continue_ != false)
    {
        arr_count = 0, count_cow = 0, count_ox = 0, count = 0, attempt_num = 0;
        srand(time(NULL));
        rand();

        rand_numb = (1000 + rand() % 9000);
        for (int i = 1000; i >= 1; i /= 10)
        {
            arr_rand_system[arr_count] = (rand_numb / i) % 10;
            arr_count++;
        }
        while (count != 4)
        {
            count_cow = 0, count_ox = 0, count = 0;
            while (true)
            {
                cout << "\n\nВведіть 4-значне число: ";
                cin >> num;
                if (cin.fail() || num < 1000 || num > 9999)
                {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "Ви ввели недопустиме число. Введіть інше\n";
                }
                else break;
            }
            arr_count = 0;
            for (int i = 1000; i >= 1; i /= 10)
            {
                arr_inputs_sign[arr_count] = (num / i) % 10;
                arr_count++;
            }





            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (arr_rand_system[i] == arr_inputs_sign[j] && i == j) // шукаємо корів
                    {
                        count_cow++;
                        count++;
                        continue;
                    }
                    else if (arr_rand_system[i] == arr_inputs_sign[j] && i != j) // шукаємо биків
                        count_ox++;
                }
            }
            


                cout << count_cow << (count_cow == 1 ? " корова, " : (count_cow == 0 ? " корів, " : " корови, "));
                cout << count_ox << (count_ox == 1 ? " бик\n" : (count_ox == 0 ? " биків\n" :" бика\n"));
                attempt_num++;
        }
        auto name_attempt = (attempt_num == 1 ? " спроба." : 
(attempt_num > 1 && attempt_num < 5 ? " спроби." : " спроб."));
        cout << "\n\nВи перемогли. Ви витратили " << attempt_num 
<< name_attempt << "\nХочите продовжити ? Якщо так - нажміть Enter, ні - іншу клавішу";
        if (!_kbhit())
        {
            n = _getch();
            if (n == 13)
                continue_ = true;
            else
                continue_ = false;
        }
    }
    
    

    return 0;
}