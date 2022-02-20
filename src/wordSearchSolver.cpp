// Tucil 1 Strategi Algoritma
// Lyora Felicya - 13520073

#include <bits/stdc++.h>
#include <string>
#include <time.h>
using namespace std;

vector<string> wordList;
vector<vector<char>> puzzle;
int comparison = 0;
time_t startP, endP;
double timePrint;

void loadFile() 
{ 
    int count = 0;

    string fileName;
    cout << "Enter name of the file (without .txt): ";
    cout << " " ;
    cin >> fileName;

    ifstream wordSearchFile;
    wordSearchFile.open("../test/" + fileName + ".txt"); 

    bool puzzleEnd = false;
    string line; 

    //Memisahkan string
    while(getline(wordSearchFile, line))
    {
        if (line == "")
        {
            puzzleEnd = true;
        }

        //Menyimpan karakter ke dalam vector 2D puzzle
        if (!puzzleEnd)
        {
            int i,j;
            char str[line.length()+1];
            strcpy(str, line.c_str());
            char *ptr = strtok(str," ");

            puzzle.push_back(vector<char>());
            while(ptr != NULL)
            {
                puzzle[count].push_back(*ptr);
                ptr = strtok(NULL," ");
            }
            count++;
        }

        //Masuk ke list kata yang ingin dicari
        else if(puzzleEnd && line != "")
        {   
            string word = line; 
            wordList.push_back(word); 
        }
    }

    wordSearchFile.close();
}

//CEK KIRI KE KANAN
bool searchRight(string wordToFind, int startI, int startJ) 
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startJ += 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
        
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found; 
}

//CEK KANAN KE KIRI
bool searchLeft(string wordToFind, int startI, int startJ)
{
    int i,j,k;
    
    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startJ -= 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK ATAS KE BAWAH
bool searchDown(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI += 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK BAWAH KE ATAS
bool searchUp(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI -= 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK DIAGONAL KIRI KE KANAN ATAS
bool searchD_UpperRight(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI -= 1;
            startJ += 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK DIAGONAL KIRI KE KANAN BAWAH
bool searchD_DownRight(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI += 1;
            startJ += 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK DIAGONAL KANAN KE KIRI ATAS
bool searchD_UpperLeft(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI -= 1;
            startJ -= 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
    }
    return found;
}

//CEK DIAGONAL KANAN KE KIRI BAWAH
bool searchD_DownLeft(string wordToFind, int startI, int startJ)
{
    int i,j,k;

    //Inisiasi vektor 2D Result yang elemennya '-'
    vector<vector<char>> result(puzzle.size(), vector<char>(puzzle[0].size(), '-'));

    bool found = false;
    bool match = true;

    for(k = 0; k < wordToFind.length(); k++)
    {
        //Memeriksa boundary
        if (startI < 0 || startI >= puzzle.size() || startJ < 0 || startJ >= puzzle[0].size())
        {
            match = false;
            break;
        }
        if(wordToFind[k] == puzzle[startI][startJ])
        {
            result[startI][startJ] = puzzle[startI][startJ];
            startI -= 1;
            startJ += 1;
        }
        else
        {
            match = false;
            break;
        }
        comparison++;
    }

    //Kata ditemukan, print solusi
    if(match)
    {
        time(&startP);
        cout << wordToFind << " found " << endl;
        for(i = 0; i < result.size(); i++)
        {
            for(j = 0;  j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        found = true;
        cout << "\n";
        time(&endP);
        timePrint = double(endP - startP);
        
    }
    return found;
}

void searchWord()
{
    int N, i, j;
    bool found = false;

    //Iterasi pencarian untuk setiap kata 
    for(N = 0; N < wordList.size(); N++)
    {
        //Menelusuri setiap huruf di dalam Puzzle
        for(i = 0; i < puzzle.size(); i++)
        {
            for(j = 0; j < puzzle[i].size(); j++)
            {
                found = searchUp(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchD_UpperRight(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchRight(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchD_DownRight(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchDown(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchD_DownLeft(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchLeft(wordList[N], i, j);
                if (found) 
                    continue;
                found = searchD_UpperLeft(wordList[N], i, j);
                if (found) 
                    continue;
            
            }
        }

    }

}

int main()
{
    time_t start,end;
    loadFile();

    int i,j;

    cout << "Your Word Search Puzzle : " << endl;
    for(i = 0; i < puzzle.size(); i++)
    {
        for(j = 0;  j < puzzle[i].size(); j++)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Solution : " << endl;

    time(&start);
    searchWord();
    time(&end);

    timePrint = endP - startP;
    double time_taken = double(end - start) - timePrint;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    cout << "Total comparison : ";
    cout << comparison;

}