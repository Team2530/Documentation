# How to create pages

1. Go to the [team documentation repository](https://github.com/Team2530/Documentation).
2. Press the '.' key on your keyboard. This will open github.dev.
3. Add a new file called pagename.md
4. Add content to the file
    - The file is a markdown file. You can read about markdown here: https://help.github.com/articles/basic-writing-and-formatting-syntax
    - You should include a title at the start, like so:
```md
# My Title
Some content.
![an image](assets/logo.svg)
```
    - You should split the document into multiple sections
6. Commit and push your code to github. The documentation repository is generally an exception to the branching rules, so feel free to push to main instead of making a pull request.

### Using Admonitions
This documentation site supports [the admonitions plugin](https://squidfunk.github.io/mkdocs-material/reference/admonitions/). This allows for easy creation of alert boxes.

For example, this code:
```md
!!! note
    Hello, world
```

Creates this:
!!! note
    Hello, world

#### Supported types
* note
* abstract
* info
* tip
* success
* question
* warning
* failure
* danger
* bug
* example
* quote

#### Changing the admonition title
You can change the admonition title by adding a string literal after the type of admonition.

=== "Markdown"
    ```md title="Adding a title"
    !!! note "Hello, world"
        Hello, world
    ```
=== "Result"
    !!! note "Hello, world"
        Hello, world

#### Collapsible
Another notable feature of admonitions is the support for collapsable alerts.
This can be achieved by replacing the exclamation points with question marks.

=== "Markdown"
    ```md
    ??? note
        Hello, world
    ```
=== "Result"
    ??? note
        Hello, world

### Adding code
Adding blocks of code to documentation is very simple. All you need to do is add something like this in the markdown file:
````md
```py
print('hello world')
```
````

#### Adding a title to the code
Sometimes you may want to add a file name or some other title to a block of code. This is possible using the title argument:

=== "Markdown"
    ````md
    ```py title="Hello, world"
    print("hello world")
    print("5 10 15 20")
    print("inconceivable")
    ```
    ````
=== "Result"
    ```py title="Hello, world"
    print("hello world")
    print("5 10 15 20")
    print("inconceivable")
    ```

#### Highlighting specific lines of code
You can highlight specific lines using `hl_lines=[...]`

=== "Markdown"
    ````md
    ```py hl_lines="2"
    print("hello world")
    print("5 10 15 20")
    print("inconceivable")
    ```
    ````

=== "Result"
    ```py hl_lines="2"
    print("hello world")
    print("5 10 15 20")
    print("inconceivable")
    ```

### Adding images
You can add images to documentation with the following syntax:  
```md
![image caption](path/to/image)
```

All images should be stored in the folder `docs/assets` for organization purposes. Also, it is better if you download any images you use and put them in this repository than link to somewhere else on the internet.

The following code displays the image below:
```md
![image caption](../assets/random-image.jpg)
```
![image caption](../assets/random-image.jpg)

### Adding diagrams
!!! warning "Tricky stuff ahead"
    Adding diagrams can be difficult, and only experienced markdown users should attempt to do it. If you don't know a lot about markdown, it is way easier to just insert an image instead.
This documentation site supports rendering of MermaidJS diagrams. You can read more about it and see some examples here: https://squidfunk.github.io/mkdocs-material/reference/diagrams/.

### Math
It is possible to insert math that is rendered properly on the page, but it may not be properly configured for this site.  
For more information, see [the official material for mkdocs page on the topic](https://squidfunk.github.io/mkdocs-material/reference/math/).
