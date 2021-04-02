// Array, Hash Table, stream

class Solution {
    public int largestUniqueNumber(int[] A) {
        return Arrays.stream(A).boxed()
            .collect(Collectors.groupingBy(e -> e, Collectors.counting()))
            .entrySet()
            .stream()
            .filter(e -> e.getValue() == 1)
            .map(e -> e.getKey())
            .max(Integer::compare)
            .orElse(-1);
    }
}