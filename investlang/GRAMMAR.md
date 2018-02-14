Valid statements are:

(statements always end in \n)

Function calls...

(assumes only one function is called, no args can be the result of a
function-call.

    function-call args...

args may be the result of a function call

    function-call(args...)

Variable declaration:

    <variable type> <variable name> = <expr>

Variable assignments:

    <variable name> = <expr>

meta-calls:

investlang supports "meta-calls" which might be things like opening a window

    meta <function-call>

imports...

    import <library>

    import <library>, <library>, ... <librar>
