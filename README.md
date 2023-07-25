# ASCII-Display-Manager

This Library lets you easily create and manipulate text objects anywhere in the terminal.

## Creating Text Object

You must first initialize the text object as an `ASCIIobject`.

```cpp
#include "Cursor.h"
#include "TextEffects.h"

int main()]
{
 ASCIIobject text;
}
```

After, you can construct the object in a few ways:
- From a text file (`.txt`)
- As a rectangle made from parameters (`canvas`)

```cpp
#include "Cursor.h"
#include "TextEffects.h"

int main()
}
 // From txt file
 ASCIIobject text;
 text.load( "image.txt" );
}
```

or alternatively

```cpp
#include "Cursor.h"
#include "TextEffects.h"

int main()
{
 // As a blank rectangle 40 wide x 20 tall
 ASCIIobject rect;
 rect.createCanvas( 40 , 20 , " " , " " );
}
```

This will load objects data into an `image` type which is defined as:

```cpp
typedef vector<string> line;
typedef vector<line> image;
```

You can place these objects anywhere in the terminal, with a few constraints:
- Must be visible on the screen
- Must be ontop of another object (can be an invisible one) to place along the x-axis

To place an object you use the `.place` method on the object you want to place.

```cpp
#include "Cursor.h"
#include "TextEffects.h"

int main()
}
 // From txt file
 ASCIIobject text;
 text.load("image.txt");
 text.place( 5 , 5 );
}
```
Since you place the object where your terminal cursor is currently, you can alternatily move your cursor with the `CsrMove` for relitive movement or `CsrMoveTo` for obsolute movement.
```cpp
#include "Cursor.h"
#include "TextEffects.h"

int main()
}
 // From txt file
 ASCIIobject text;
 text.load("image.txt");
 CsrMoveTo(5,5);
 text.place();
}
```



