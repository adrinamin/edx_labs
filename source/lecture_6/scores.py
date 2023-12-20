# Get scores
scores = []
for i in range(3):
    score = int(input("Enter score: "))
    scores.append(score)
    
# Calculate average
average = sum(scores) / len(scores)
print(f"Average score: {average}")