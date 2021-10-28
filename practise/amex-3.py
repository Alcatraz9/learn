def solve(s):
    # split rows
    rows = s.split('\\n')
    for row in rows:
        # check for NULL in row
        data = row.split(',')
        if('NULL' in data):
            rows.remove(row)

    # make result string using the data we get
    res = "\\n".join([str(word) for word in rows])
    return res


S = input()
print(solve(S))