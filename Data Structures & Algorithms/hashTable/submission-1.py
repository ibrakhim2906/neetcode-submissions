
class HashTable:
    
    def __init__(self, capacity: int):

        self.capacity = capacity
        self.buckets = [[] for _ in range(self.capacity)]
        self.size = 0


    def insert(self, key: int, value: int) -> None:

        bucket_idx = self._hash(key)
        bucket = self.buckets[bucket_idx]

        for i, (k, v) in enumerate(bucket):
            if (k==key):
                bucket[i] = (key, value)
                return 
            
        bucket.append((key, value))
        self.size+=1

        if self.size/self.capacity>=0.5:
            self.resize()


    def get(self, key: int) -> int:

        bucket_idx = self._hash(key)
        bucket = self.buckets[bucket_idx]

        for (k, v) in bucket:
            if k == key:
                return v
        
        return -1


    def remove(self, key: int) -> bool:

        bucket_idx = self._hash(key)
        bucket = self.buckets[bucket_idx]

        for i, (k, v) in enumerate(bucket):
            if k==key:
                bucket.pop(i)
                self.size-=1
                return True

        return False
        
    def getSize(self) -> int:

        return self.size


    def getCapacity(self) -> int:

        return self.capacity


    def resize(self) -> None:

        old_buckets = self.buckets

        self.capacity *= 2
        self.buckets = [[] for _ in range(self.capacity)]
        self.size = 0

        for bucket in old_buckets:
            for (k, v) in bucket:
                self.insert(k, v)


    def _hash(self, key: int) -> int:
        return key % self.capacity

