# The *.inp files reader

### Overview

Reading a file is divided into three phases:
- Tokenization the input
- Parsing the tokens into keywords tree
- Building the model

#### Tokenization

Tokenizer is based on simple rules:
- Line starting with ** is interpreted as a comment.
- Line starting with * is interpreted as a keyword.
- Other lines are interpreted as data lines.

#### Parsing the tokens

Meaning of some tokens may differ depending on context. Every token is passed to the current keyword in the tree, and the node decides what to do with it, basing on the type of keyword.

#### Building a model

After traversing the keywords tree the model is build. In current version, It's just reading the data from the global scope. In the future keywords like _part_ and _assembly_ will be more important.

### Building the library and examples

The library uses **CMake** build system. There is simple example of building the library.

    mkdir build
    cmake path/to/the/source
    make

After setup of project use this command to compile the **Doxygen** files.

    make doc

Doxygen requieres to add {#mainpage} in the main page.

### Simple Usage

Start with reading a file and make tokens form it.

    auto tokens = Tokenizer::fromFile("filename.inp");

Then one can parse the tokens into tree. Tokenizer returns _std::vector__ of _std::unique_ptr_, so we have to use _std::move_ to pass it directly to the _Parser_.

    auto keywordsTree = Parser::parse(std::move(tokens));

Building the model is really easy. Just pass the tree into _Model_ constructor.

    InpReader::Model m(std::move(keywordsTree));

Once you have a model, just read it's properties.

    auto elements = model.getElements();
    auto nodes = model.getNodes();
    auto steps = model.getSteps();


### References

The keywords documentation can be found on [keyword doc].


  [keyword doc]: http://www.maths.cam.ac.uk/computing/software/abaqus_docs/docs/v6.12/pdf_books/KEYWORD.pdf

