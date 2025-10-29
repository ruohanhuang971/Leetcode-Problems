# **Trie (Prefix Tree)**

- tree-like structure used to store strings, where each node represents a character
- Uses: prefix-based problems
    - autocomplete, spell check, or searching for words that start with a prefix

**Node definition**
```js
class TrieNode {
  constructor() {
    this.children = {}; // map from char → TrieNode
    this.isEnd = false; // marks end of word
  }
}
```

**Trie class**
```js
class Trie {
  constructor() {
    this.root = new TrieNode();
  }

  insert(word) {
    let node = this.root;
    for (const ch of word) {
      if (!node.children[ch]) node.children[ch] = new TrieNode();
      node = node.children[ch];
    }
    node.isEnd = true;
  }

  search(word) {
    let node = this.root;
    for (const ch of word) {
      if (!node.children[ch]) return false;
      node = node.children[ch];
    }
    return node.isEnd;
  }

  startsWith(prefix) {
    let node = this.root;
    for (const ch of prefix) {
      if (!node.children[ch]) return false;
      node = node.children[ch];
    }
    return true;
  }
}

```