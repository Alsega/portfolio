import random

words_bank = [
    'автострада', 'бензин', 'инопланетянин',
    'самолет', 'библиотека', 'шайба',
    'олимпиада'
]

#random_idx = ...
secret_word = random.choice(words_bank)
#print(secret_word)

gamer_word = ['*'] * len(secret_word)
print(''.join(gamer_word))

# gamer_word[2] = 'т' # mutable vs inmutable
# print(''.join(gamer_word))

errors_counter = 0
while True:
    letter=input('введите ОДНУ русскую букву: ').lower()
    # letter ard(), ne
    if len(letter) != 1:
        continue

    if letter in secret_word:
        # pass # заглушка
        # brute_force -> hash table => dict
        i = 0
        for symbol in secret_word: #enumerate()
            #print(symbol)
            if symbol == letter:
                gamer_word[i] = letter
            i += 1        
        if '*' not in gamer_word:   # 0(n), 0(1) -> hash table: dict, set
            print('win')
            break
    else:
        errors_counter += 1
        print('ошибок допущено:', errors_counter)
        if errors_counter == 8:
            print('game over')
            break
    print(''.join(gamer_word))