#### std::flush
- sends whatever is in the output buffer to the connected stream(the terminal)
- when we use std::cout, data doesn't directly go the terminal, it's first put into this buffer
- when this buffer is full, all the data inside it is sent in one go

#### std::setw()    (from <iomanip>)
- 'setwidth', `std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::endl;`
- whatever is to the right of setw() , is going to appear in a 'cell', who's total length is going to be 10 characters wide
- For eg: "Name" is 4 chars long, the rest of the 6 places are filled with whitespaces, and it's printed out like a single word

### justification (from <ios>)
#### std::right, std::left , std::internal
```cpp
    int col_width = 20;

    std::cout << std::right;
    std::cout << std::setw(20) << "Tejas" << std::endl;
```
- In the cell of 20 chars wide, the word "Tejas" will be aligned to the right
