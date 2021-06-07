#include<bits/stdc++.h>
using namespace std;


signed main()
{
    // Boost;
    // IO();
    // ifstream inFile("input.txt");
    ifstream inFile("output.txt");

    // ofstream outFile("IR.txt");
//3
    ofstream outFile("input.txt");
    // ofstream outFile("output.txt");
    
    unordered_map<string,char> mp;


    long long int encodedLength,i,chartSize;

    string encLen,chartSiz,s;

    getline(inFile,encLen);
    getline(inFile,chartSiz);

    try{

    if(encodedLength = stoi(encLen));
    chartSize = stoi(chartSiz);

    // throw exception;
    }
    catch (int m){
        cout<<encLen<<endl;
        cout<<chartSiz<<endl;
        return 0;
    }

    // cout<<encodedLength<<endl;
    // cout<<chartSize<<endl;

    while(chartSize--)
    {
        getline(inFile,s);

        if(s.length()==0)
        {
            getline(inFile,s);
            mp[s] = '\n';
        }
        else
        {
            mp[s.substr(1)] = s[0];
        }

    }

    // for(auto it : mp)
    // {
    //     cout<<it.first<<" - "<<it.second<<endl;
    // }




    char ch;

    // cout<<ch<<endl;


    // for(auto it : pathMap)
    // {
    //     mp[it.second] = it.first;
    // }


    string ss,decodedEncoded;

    while(inFile.get(ch))
    {
        ss += ch;
    }


    for(i=0;i<ss.length();++i)
    {

        // string bits = getBinary(ss[i]);
        // decodedEncoded += bits;

        for(int j =7; j>=0;--j)
        {
            if( ss[i] & (1<<j))
            {
                decodedEncoded += '1';
            }
            else
            {
                decodedEncoded += '0';
            }
            if(decodedEncoded.length()==encodedLength)
            {
                break;
            }
        }



    }

    string temp,ans;

    // cout<<" DecodedEncoded - "<<decodedEncoded<<endl;

    // if(decodedEncoded == encodedString)
    // {
    //     cout<<"Correct"<<endl;
    // }
    // else
    // {
    //     cout<<"In-correct"<<endl;
    // }

    for(i=0;i<decodedEncoded.length();++i)
    {
        temp += decodedEncoded[i];

        if(mp.count(temp)>0)
        {
            ans += mp[temp];
            temp ="";
        }

    } 

    outFile<<ans;

    outFile.flush();

    inFile.close();

    outFile.close();


    return 0;
}


//Author : nikhilkd1999