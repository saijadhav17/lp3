import heapq
from collections import Counter, defaultdict

class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

def huffman_encoding(data):
    # Step 1: Calculate frequency of each character
    frequency = Counter(data)
    
    # Step 2: Build priority queue (min-heap)
    heap = [Node(freq, symbol) for symbol, freq in frequency.items()]
    heapq.heapify(heap)
    
    # Step 3: Build Huffman Tree
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = Node(left.freq + right.freq, None, left, right)
        heapq.heappush(heap, merged)
    root = heap[0]
    
    # Step 4: Generate Huffman Codes
    huffman_codes = {}
    def generate_codes(node, current_code=""):
        if node is None:
            return
        if node.symbol is not None:  # Leaf node
            huffman_codes[node.symbol] = current_code
            return
        generate_codes(node.left, current_code + "0")
        generate_codes(node.right, current_code + "1")
    
    generate_codes(root)
    
    # Step 5: Encode data
    encoded_data = ''.join(huffman_codes[char] for char in data)
    return encoded_data, huffman_codes

# Example usage
data = "simple huffman example"
encoded_data, huffman_codes = huffman_encoding(data)
print("Huffman Codes:", huffman_codes)
print("Encoded Data:", encoded_data)


