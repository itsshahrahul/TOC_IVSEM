class Grammar:
    def __init__(self, productions):
        self.productions = productions
    def leftmost_derivation(self, start_symbol, target_string):
        current_string = start_symbol
        derivation_steps = [current_string]
        while current_string != target_string:
            for i, char in enumerate(current_string):
                if char in self.productions:
                    production = self.productions[char][0]  
                    current_string = current_string[:i] + production + current_string[i + 1:]
                    derivation_steps.append(current_string)
                    break
            else:
                break 
        if 'S' in derivation_steps[-1]:
            derivation_steps[-1] = derivation_steps[-1].replace('S', '') 
            return derivation_steps
    def rightmost_derivation(self, start_symbol, target_string):
        current_string = start_symbol
        derivation_steps = [current_string]
        while current_string != target_string:
            for i in range(len(current_string) - 1, -1, -1):
                if current_string[i] in self.productions:  
                    production = self.productions[current_string[i]][0] 
                    current_string = current_string[:i] + production + current_string[i + 1:]
                    derivation_steps.append(current_string)
                    break
            else:
                break
        if 'S' in derivation_steps[-1]:
            derivation_steps[-1] = derivation_steps[-1].replace('S', '')  
        return derivation_steps
def main():
    start_symbol = input("Enter the start symbol: ")
    productions = {}
    while True:
        production_input = input("Enter a production rule (or type 'done' to finish): ")
        if production_input.lower() == 'done':
            break
        try:
            non_terminal, production = production_input.split('->')
            non_terminal = non_terminal.strip()
            production = production.strip().split('|') 
            productions[non_terminal] = [prod.strip() for prod in production]
        except ValueError:
            print("Invalid input format. Please use 'A->B|C' format.")
    target_string = input("Enter the target string: ")
    grammar = Grammar(productions)
    leftmost_steps = grammar.leftmost_derivation(start_symbol, target_string)
    rightmost_steps = grammar.rightmost_derivation(start_symbol, target_string)
    print("\nLeftmost Derivation Steps:")
    for step in leftmost_steps:
        print(step)
    print("\nRightmost Derivation Steps:")
    for step in rightmost_steps:
        print(step)
if __name__ == "__main__":
    main()
