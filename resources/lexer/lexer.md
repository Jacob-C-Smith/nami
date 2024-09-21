# Nami > Lexer

```
╭────────╮   ╭───────╮   ╭────────╮   ╭──────────────╮   ╭────────╮   ╭────────╮   ╭────────╮
│ source │-->│ lexer │-->│ parser │-->│ type checker │-->│        │-->│        │-->│        │
╰────────╯   ╰───────╯   ╰────────╯   ╰──────────────╯   ╰────────╯   ╰────────╯   ╰────────╯
```

The lexer scans a nami source code file, and produces a sequence of tokens 