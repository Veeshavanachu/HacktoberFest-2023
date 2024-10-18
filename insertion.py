def insertion_sort(arr):
    # Traverse from 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be compared
        j = i - 1
        
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]  # Shift element to the right
            j -= 1
            
        arr[j + 1] = key  # Place the key in its correct position

# Get user input
if __name__ == "__main__":
    # Ask user to input a list of numbers separated by spaces
    user_input = input("Enter numbers separated by spaces: ")
    # Split the input string into a list and convert each to an integer
    data = list(map(int, user_input.split()))
    
    print("Original array:", data)
    insertion_sort(data)
    print("Sorted array:", data)
