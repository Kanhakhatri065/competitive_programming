#include <iostream>

using namespace std;


int main(){
    int total_books,max_chapters;
    cin>>total_books>>max_chapters;

    int chapter_per_book[total_books];

    for(int i = 0;i < total_books;i++){
        cin>>chapter_per_book[i];
    }

    int first = 0;

    while(chapter_per_book[first] <= max_chapters){
        first++;
    }

    int last = total_books - 1;

    while(chapter_per_book[last] <= max_chapters){
        last--;
    }

    int left = last - first + 1;

    cout << left << endl;

    return 0;
}