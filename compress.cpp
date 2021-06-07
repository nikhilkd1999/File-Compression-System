#include<bits/stdc++.h>
using namespace std;


void writeInBits(int n, char & buff, int &totalBits, ofstream & outFile)
{
    if(totalBits==8)
    {
        outFile<<buff;
        buff = 0;
        totalBits = 0;
    }

    int mask;

    mask = (1<<(7-totalBits)) ;
    if(n==1)
    {
        buff = buff | mask;
    }
    else
    {
        mask = ~mask;
        buff = buff & mask;
    }

    ++totalBits;

}


string getBinary(char ch)
{
    string ans;

    // ch = 'a';
    // ch = 'ç' ;

    int n = ch;

    // n = n | ch;
    cout<<n<<" - ";

    stack<int> st;


    while(st.size()<8)
    {
        st.push(n%2);
        n = n /2;
    }


    while(!st.empty())
    {
        if(st.top()==1)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
        st.pop();
    }

    cout<<ch<<" - ";
    cout<<ans<<endl;

    return ans;





}



class Node
{
    public:

    int freq;
    char ch;

    Node * left;
    Node * right;

    Node(char c, int f)
    {
        freq = f;
        ch = c;
        left = NULL;
        right = NULL;
    }
};

class comp
{
    public :
    bool operator()(const Node *n1 ,const  Node *n2)
    {
        return n1->freq > n2->freq;
    }

};





void inorder(Node * root,string path, unordered_map<char,string> & pathMap)
{
    if(root==NULL)
    {
        return;
    }


    inorder(root->left,path+'0',pathMap);

    // cout<<root->ch;
    if(root->ch!='~')
    {
        pathMap[root->ch] = path;
    }

    inorder(root->right,path+'1',pathMap);


}








signed main()
{
    // Boost;
    // IO();

    // ifstream inFile("IR.txt");

    ifstream inFile("input.txt");
    // ifstream inFile("output.txt");
//4
    ofstream outFile("output.txt");
    // ofstream outFile("input.txt");


    char ch;
    string s,encodedString;
    while(inFile.get(ch))
    {
        s += ch;
    }
    // cout<<s<<endl;
    // cout<<str<<endl;
    inFile.close();
    
    // cout<<s<<endl;

    // string s;
    int i,j;

    unordered_map<char,int> frequency;


    for(i=0;i<s.length();++i)
    {
        frequency[s[i]]++;
    }

    priority_queue<Node *, vector<Node*>,comp> pq;

    Node * nn;

    for(auto it :frequency)
    {

        nn = new Node(it.first,it.second);

        pq.push(nn);

    }


    // cout<<endl;



    while(pq.size()>1)
    {



        Node * l =pq.top(); pq.pop();
        Node * r =pq.top(); pq.pop();

        nn = new Node( '~' ,  l->freq + r->freq );

        nn->left = l;
        nn->right = r;

        pq.push(nn);


    }

    // cout<<endl;

    unordered_map<char,string> pathMap;

    string path;


    inorder(pq.top(),path,pathMap);
    cout<<endl;



    for(auto it : pathMap)
    {
        cout<<it.first<<" - "<<it.second<<endl;
    }

    cout<<"Unique Characters = "<<pathMap.size()<<endl;

    cout<<endl;
    // cout<<endl;


    for(i=0;i<s.length();++i)
    {
        // cout<<pathMap[s[i]]<<" ";
        encodedString += pathMap[s[i]];
    }

    outFile<<(encodedString.length());
    outFile<<endl;
    outFile<<(pathMap.size());
    outFile<<endl;

    for(auto it : pathMap)
    {
        outFile<<it.first<<it.second;
        outFile<<endl;
        
    }
    // cout<<" Encoded - "<<encodedString<<endl;

    cout.flush();

    char buff = 0;
    int totalBits=0;

    for(i=0;i<encodedString.length();++i)
    {
        if(encodedString[i]=='1')
        {
            writeInBits(1,buff,totalBits,outFile);
        }
        else
        {
            writeInBits(0,buff,totalBits,outFile);
        }
    }

    outFile<<buff;

//  char zz = 155;
    // outFile<<zz;

// cout<<"-----------"<<zz<<endl;

    outFile.close();


/////////////////////////////////////////////////   Decompress
// {

//     unordered_map<string,char> mp;

//     for(auto it : pathMap)
//     {
//         mp[it.second] = it.first;
//     }

//     ifstream inFile("output.txt");
//     ofstream outFile("IR.txt");

//     string ss,decodedEncoded;

//     while(inFile.get(ch))
//     {
//         ss += ch;
//     }


//     for(i=0;i<ss.length();++i)
//     {

//         // string bits = getBinary(ss[i]);
//         // decodedEncoded += bits;

//         for(int j =7; j>=0;--j)
//         {
//             if( ss[i] & (1<<j))
//             {
//                 decodedEncoded += '1';
//             }
//             else
//             {
//                 decodedEncoded += '0';
//             }
//             if(decodedEncoded.length()==encodedString.length())
//             {
//                 break;
//             }
//         }



//     }

//     string temp,ans;

//     // cout<<" DecodedEncoded - "<<decodedEncoded<<endl;

//     if(decodedEncoded == encodedString)
//     {
//         cout<<"Correct"<<endl;
//     }
//     else
//     {
//         cout<<"In-correct"<<endl;
//     }

//     for(i=0;i<decodedEncoded.length();++i)
//     {
//         temp += decodedEncoded[i];

//         if(mp.count(temp)>0)
//         {
//             ans += mp[temp];
//             temp ="";
//         }

//     } 

//     outFile<<ans;


// }





    return 0;
}


//Author : nikhilkd1999