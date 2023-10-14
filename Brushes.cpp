#include <bits/stdc++.h>
using namespace std;

int minimumBrushstrokes(const string &canvas) {
    multiset<char> colors;
    colors.insert(canvas[0]);
    int i=0,j=1;
    while(j<canvas.length())
    {
        if(canvas[i]!=canvas[j])  
        {
          
            
        }


    }


    for (int i = 1; i < canvas.length(); i++)
    {
        if(canvas[i] != canvas[i-1]  &&  canvas[i] != canvas[0])
            colors.insert(canvas[i]);
    }
    return colors.size();
}

int main() {
    string canvas;
    cin >> canvas;

    /* if (canvas.length() > 50) {
        cout << "La longitud del lienzo debe ser de hasta 50 caracteres." <<endl;
        return 1;
    } */

    int result = minimumBrushstrokes(canvas);

    cout << result <<endl;

    return 0;
}