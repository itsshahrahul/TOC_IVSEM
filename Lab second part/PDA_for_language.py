class PDA:
    def __init__(self):
        self.stack = []
        self.state = 'q_0'
        self.accept_state = 'q_f'
    def transition(self, symbol):
        if self.state == 'q_0' and symbol == 'a':
            self.state = 'q_1'
            self.stack.append('a')
        elif self.state == 'q_1' and symbol == 'a':
            self.stack.append('a')
        elif self.state == 'q_1' and symbol == 'b' and self.stack and self.stack[-1] == 'a':
            self.state = 'q_2'
            self.stack.pop()
        elif self.state == 'q_2' and symbol == 'b' and self.stack and self.stack[-1] == 'a':
            self.stack.pop()
        else:
            self.state = 'reject'
    def process(self, input_string):
        for symbol in input_string:
            self.transition(symbol)
            if self.state == 'reject':
                return False

        if self.state == 'q_2' and not self.stack:
            self.state = self.accept_state
            return True
        return False
pda = PDA()
print("Enter a string of 'a's and 'b's:")
input_string = input().strip()
if pda.process(input_string):
    print(f"The input '{input_string}' is accepted by the PDA.")
else:
    print(f"The input '{input_string}' is rejected by the PDA.")
