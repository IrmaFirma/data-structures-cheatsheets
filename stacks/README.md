# Stack 
- Also known as LIFO (last in first out)

```cpp
  push ↓   ↑ pop
      ┌─────┐
      │  D  │  ← top
      ├─────┤
      │  C  │
      ├─────┤
      │  B  │
      ├─────┤
      │  A  │
      └─────┘
```

## Operations
### `push()`: 
- $O(1)$
- occasionally, needs to be resized $O(n)$ but cost still amortizes to $O(1)$ across all `push()`es

### `pop()`: 
- runtime complexity: $O(1)$
```cpp
int pop() {
  // Guard against popping an empty stack
  if (topIndex == -1) {
    throw std::underflow_error("pop() called on empty stack");
  }

  // Retrieve the top value and shrink logical size
  return data[topIndex--];
}
```

### `peek()` / `top()`: $O(1)$

