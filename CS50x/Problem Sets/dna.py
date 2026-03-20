import csv
import sys

# Ensure correct usage
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

database_file = sys.argv[1]
sequence_file = sys.argv[2]

# Load DNA database
people = []
with open(database_file, newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    # Strip column names to avoid hidden whitespace
    strs = [field.strip() for field in reader.fieldnames if field != "name"]
    for row in reader:
        person = {"name": row["name"]}
        for str_seq in strs:
            # Convert STR counts to integers
            person[str_seq] = int(row[str_seq])
        people.append(person)

# Load DNA sequence
with open(sequence_file) as f:
    dna_sequence = f.read().strip()

# Helper function to find longest consecutive repeats
def longest_match(sequence, subsequence):
    longest = 0
    sub_len = len(subsequence)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while sequence[i + count*sub_len : i + (count+1)*sub_len] == subsequence:
            count += 1
        longest = max(longest, count)
    return longest

# Compute STR counts for the sequence
dna_str_counts = {str_seq: longest_match(dna_sequence, str_seq) for str_seq in strs}

# Compare counts against each person in the database
for person in people:
    if all(person[str_seq] == dna_str_counts[str_seq] for str_seq in strs):
        print(person["name"])
        break
else:
    print("No match")
