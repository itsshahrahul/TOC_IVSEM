class TuringMachine:
    def __init__(self, tape, blank_symbol='#'):
        self.tape = list(tape) + [blank_symbol]
        self.blank_symbol = blank_symbol
        self.head_position = 0
        self.state = 'q0'
        self.accept_state = 'q_accept'
        self.reject_state = 'q_reject'
    
    def move_head(self, direction):
        if direction == 'R':
            self.head_position += 1
        elif direction == 'L':
            self.head_position = max(0, self.head_position - 1)
    
    def get_current_symbol(self):
        return self.tape[self.head_position]

    def write_symbol(self, symbol):
        self.tape[self.head_position] = symbol

    def transition(self):
        symbol = self.get_current_symbol()
        if self.state == 'q0':
            if symbol == 'a':
                self.write_symbol('X')
                self.state = 'q1'
                self.move_head('R')
            elif symbol == 'Y' or symbol == self.blank_symbol:
                self.state = self.accept_state
            else:
                self.state = self.reject_state
        elif self.state == 'q1':
            if symbol == 'a':
                self.move_head('R')
            elif symbol == 'b':
                self.write_symbol('Y')
                self.state = 'q2'
                self.move_head('L')
            elif symbol == 'Y':
                self.move_head('R')
            else:
                self.state = self.reject_state
        elif self.state == 'q2':
            if symbol == 'a' or symbol == 'Y':
                self.move_head('L')
            elif symbol == 'X':
                self.state = 'q0'
                self.move_head('R')
            else:
                self.state = self.reject_state

    def run(self):
        while self.state not in {self.accept_state, self.reject_state}:
            self.transition()
        return self.state == self.accept_state

tape = input("Enter the input tape: ")
tm = TuringMachine(tape)
result = tm.run()
print("Accepted" if result else "Rejected")
