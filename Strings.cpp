#include <iostream>
#include <algorithm>
#include <string>

class String
{
private:
    std::string str{};
    int length{};
public:
    explicit String() { std::cin >> str; }
    void to_upper();
    void to_lower();
    void reverse_1();
    void search_for_dup_1();
    void search_for_dup_2();
    void search_for_dup_3();
    int find_the_length();
    int count_words();
    int count_vowels();
    int count_Consonants();
    bool is_valid();
    [[maybe_unused]] bool isPalindrom();
    [[maybe_unused]] bool isAnagrame_1(std::string ste);
    bool isAnagrame_2();
    std::string reverse_2();
};

int String :: find_the_length()
{
    while(str[length] != '\0') length++;
    return length;
}

void String :: to_upper()
{
    find_the_length();
    for(int i = 0; i < length; i++) {
        if(str[i] <= 122 && str[i] >= 97) str[i] -= 32;
        else continue;
    }
    std::cout << str;
}

void String :: to_lower()
{
    find_the_length();
    for(int i = 0; i < length; i++) {
        if(str[i] <= 90 && str[i] >= 65) str[i] += 32;
        else continue;
    }
    std::cout << str;
}

int String :: count_words()
{
    int word(1);
    find_the_length();
    for(int i = 0; i < length; i++) {
        if(str[i] == ' ' && str[i - 1] != ' ') word++;
    }
    return word;
}

int String :: count_vowels() {
    find_the_length();
    int Vowels(0);
    for(int i = 0; i < length; i++) {
        if(str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o' ||
        str[i] == 'a' - 32 || str[i] == 'i' - 32 || str[i] == 'u' - 32 || str[i] == 'e' - 32 ||
        str[i] == 'o' - 32)
            Vowels++;
    }
    return Vowels;
}

int String :: count_Consonants () {
    find_the_length();
    int Consonants(0);
    for(int i = 0; i < length; i++) {
        if(!(str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o' ||
           str[i] == 'a' - 32 || str[i] == 'i' - 32 || str[i] == 'u' - 32 || str[i] == 'e' - 32 ||
           str[i] == 'o' - 32) && (str[i] <= 90 && str[i] >= 65 || str[i] <= 122 && str[i] >= 97))
            Consonants++;
    }
    return Consonants;
}

bool String :: is_valid() {
    find_the_length();
    for(char c : str)
        if(!((c <= 90 && c >= 65 || c <= 122 && c >= 97) || (c <= 57 && c >= 48))) return false;
    return true;
}

void String::reverse_1()
{
    find_the_length();
    for(int i = 0, j = length - 1; i < j; i++, j--)
        std::swap(str[i], str[j]);
    std::cout << str;
}

std::string String::reverse_2()
{
    find_the_length();
    std::string ste("");
    for(int i = length - 1; i >= 0; i--)
        ste += str[i];
    return ste;
}

[[maybe_unused]] bool String :: isPalindrom() {
    String *i;
    std::string ste = reverse_2();
    return ste == str;
}

void String :: search_for_dup_1() {
    find_the_length();
    int i, l = *std::min_element(str.begin(), str.end()), h = *std::max_element(str.begin(), str.end());
    int *Hash = new int[h];
    for(i = l; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[str[i]]++;
    for(i = l; i <= h; i++)
        if(Hash[i] > 1)
            std::cout << char(i) << " appear " << Hash[i] << " times" << '\n';
    delete [] Hash;
}

void String :: search_for_dup_2()
{
    find_the_length();
    int count(1);
    for(int i = 0; i < length - 1; i++) {
        count = 1;
        if(str[i] == 126) continue;
        for(int j = i + 1; j < length; j++) {
            if(str[i] == str[j])  {
                count++;
                str[j] = '~';
            }
        }
        if(count > 1) std::cout << str[i] << " appear " << count << " times" << '\n';
    }
}

[[maybe_unused]] bool String::isAnagrame_1(std::string ste)
{
    find_the_length();
    for(int i = 0; i < length; i++) {
        auto sear = ste.find(str[i]);
        if(sear != std::string::npos) {
            ste[sear] = '~';
            continue;
        }
        else return false;
    }
    return true;
}

bool String::isAnagrame_2()
{
    find_the_length();
    auto *oo = new String;
    oo->find_the_length();
    int i, l = *std::min_element(str.begin(), str.end()), h = *std::max_element(str.begin(), str.end()) + 1;
    int *Hash = new int[h];
    for(i = l; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[str[i]]++;
    for(i = 0; i < oo->length; i++) {
        Hash[oo->str[i]]--;
        if(Hash[oo->str[i]] == -1) return false;
    }
    delete [] Hash;
    delete oo;
    return true;
}

void String::search_for_dup_3()
{
    find_the_length();
    long int H = 0, x = 0;
    for(int i = 0; i < length; i++) {
        x = 1 << (str[i] - 97);
        if((x & H) > 0) std::cout << str[i] << " is duplicated";
        else H |= x;
    }
}
int main ()
{
    auto *o = new String;
    o->search_for_dup_3();
    //std::cout << o->isAnagrame_1("aa") << '\n';
    delete o;
}
