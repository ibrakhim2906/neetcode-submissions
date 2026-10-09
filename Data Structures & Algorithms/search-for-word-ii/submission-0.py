from typing import List

class TrieNode:
    __slots__ = ('children', 'word')
    def __init__(self):
        self.children = {}
        self.word = None  # set to the full word at terminal nodes


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # 1. Build trie of all words
        root = TrieNode()
        for w in words:
            node = root
            for ch in w:
                node = node.children.setdefault(ch, TrieNode())
            node.word = w

        rows, cols = len(board), len(board[0])
        result = []

        def dfs(r, c, parent):
            ch = board[r][c]
            node = parent.children.get(ch)
            if node is None:
                return

            if node.word is not None:
                result.append(node.word)
                node.word = None  # avoid duplicate results

            # mark visited
            board[r][c] = '#'

            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                    dfs(nr, nc, node)

            # restore
            board[r][c] = ch

            # optional optimization: prune leaf nodes with no children
            if not node.children:
                parent.children.pop(ch, None)

        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)

        return result
