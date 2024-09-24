    #include <cctype>
    #include <iostream>
    #include <cstring>
    using namespace std;
    int main()
    {
        char str[100];
        cin >> str;
        int count = 0;
        for (int i=0; i<=strlen(str); i++)
        {
            if (isblank(str[i]))
                count ++;
        }
        cout << "Number of blank characters: " << count << endl;
        return 0;
    }
