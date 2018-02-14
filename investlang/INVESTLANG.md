A scripting language focused on investing environments.

Dynamically typed.

The object types are:

| type    | description | special 'methods' |
|---------|-------------|-------------------|
| number  | rational    |                   |
| asset   | an asset    | supportsHistory(), value(), valueAtTime() |
| array   | homogenous  | getElement()      |
| boolean |             |                   |
| datetime|                                 |
| string  | UTF-16 string | |

Possible data types:

* Image/dataset

it supports if...else if... else patterns

while loop (break, continue)

functions

Creating instance of object

## number
    1
    1.5
    1 1/2

## asset (stock)
    $stock APPL

## datetime
Multiple formats supported

# Hello World

    print "Hello, World!"

# Get APPL price value at date

    val $stock APPL GMT-7 5 April 2013
