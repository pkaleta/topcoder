#include <string>
using namespace std;

class EqualizeStrings {
    public:

        char closest(char a, char b)
        {
            if (a == 'a' || b == 'a')
                return 'a';

            if (b < a) {
                char tmp = a;
                a = b;
                b = tmp;
            }

            int d1 = (b-a);
            int d2 = (('z'-b)+(a-'a')+1);

            if (d1 < d2)
                return a;
            else
                return 'a';
        }

        string getEq(string s, string t) {
            string result = "";

            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == t[i])
                    result += s[i];
                else
                    result += closest(s[i], t[i]);
            }
            return result;
        }
};
