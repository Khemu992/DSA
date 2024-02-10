//String 

//1) 
/* ASCII CODE {Amarican Standard Code for informatation interchange}
A to Z == 65 to 90
a to z == 97 to  122
0 to 9 == 48 to 57
enter =10
space =13
esc=27
*/
 
//2)  '/0'=====String Delimeter Or Null character Or String Terminator



#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int Length(string S)
{
    int length=0;
    for(int i=0; S[i]!='\0'; i++)length++;
    return length;
}

void ChangeCase(string S)
{
    for(int i=0; S[i]!='\0'; i++)
    {
        if(S[i]>=65 && S[i]<=90)S[i]+=32;
        else if(S[i]>=97 && S[i]<=122)S[i]-=32;
    }
}

int Counting_Vowels(string s)
{
    int vowels=0;
    for(int i=0;s[i]!='\0'; i++)
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
    s[i]=='A' || s[i]=='E' || s[i]=='I' ||s[i]=='O' || s[i]=='U')vowels++;
    return vowels;
}

int Counting_Consonant(string s)
{
    int consonants=0;
    for(int i=0;s[i]!='\0'; i++)
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
    s[i]=='A' || s[i]=='E' || s[i]=='I' ||s[i]=='O' || s[i]=='U' );
    else if(s[i]<=90 && s[i]>=65 || s[i]<=122 && s[i]>=97)consonants++;
    
    return consonants;
}

int Counting_Words_1(string s)
{
    int words=0;
    for(int i=0;s[i]!='\0'; i++)
    {
        if(s[i]==' ')words++;
    }
    return words+1;
 
}

int Counting_Words_2(string s)
{
    int words=0;int i=0;
    if(s[i]==' ')i++;
    for(;s[i]!='\0'; i++)
    {
        if(s[i]==' ' && s[i-1]!=' ')words++;
    }
    if(s[Length(s)-1]!=' ' && s[0]==' ')return ++words;
    else if(s[Length(s)-1]==' ' || s[0]==' ')return words;
    return words+1;
}

int isPalindrom(string s){
    string temp=s;
    for(int i=0,j=s.size()-1; j>i; i++,j--){
        char t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    if(temp==s)return 1;
    return 0;
}

void Dublicates(string s){
    int H[26];
    for(int i=0; i<26;i++)H[i]=0;
    for(int i=0; s[i]!='\0'; i++){
        cout<<int(s[i]-97)<<endl;
        H[s[i]-97]++;
    }
    for(int i=0; i<26; i++)if(H[i]>0)cout<<char(i+97)<<" is repeated "<<H[i]<<" Tines" <<endl;
}

int isAnagram(string s1,string s2){
    int H[26];
    for(int i=0; i<26; i++)H[i]=0;
    
    for(int i=0; s1[i]!='\0'; i++)H[s1[i]-97]++;
    for(int i=0; s2[i]!='\0'; i++)H[s2[i]-97]--;
    
    for(int i=0; i<26; i++){if(H[i]!=0){return 0; break;}}
    return 1;
}
int main()

{
        string s;
        cout<<"Eneter string "<<endl;
        getline(cin,s);
        cout<<s<<endl;
       
    // 1) Length...... 
    /*cout<<"Length of S string is "<<Length(s);*/
    
    // 2) Changing Case.......
    /*ChangeCase(s);cout<<s;*/
    
    // 3) Counting Vowels.......
    /*cout<<"Number of Vowels is "<<Counting_Vowels(s)<<endl;*/
    
    // 4) Counting Consonants.....
    /*cout<<"Number of Consonant is "<<Counting_Consonant(s)<<endl;*/
    
    // 5) counting words....
    /*cout<<"Number of words is "<<Counting_Words_2(s)<<endl;*/
    
    // 6) Reversing string method 1.....
    /*for(int i=s.size()-1,j=0; i>j; i--,j++)
    {
        char t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    cout<<s;*/
    
    // 7) Palindrom.......
    /*if(isPalindrom(s))cout<<"Yes "<<s<<" is Palindrom "<<endl;
    else cout<<"No "<<s<<" is not a Palindrom "<<endl;*/
    
    // 8) Dublicates
    //Dublicates(s);
    
    
    //9) Anagram.....
    /*string s2;
    cout<<"Enter second string "<<endl;
    cin>>s2;
    if(isAnagram(s,s2))cout<<"Strings are anagram "<<endl;
    else cout<<"string are not anagram "<<endl;
    */
    
    
    
    return 0;
}
