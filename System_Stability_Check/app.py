from Engine.engine import RoutheEngine

if __name__ == '__main__':
    input = input("Enter the coefficients of the polynomial separated by space: ")
    input = list(map(int, input.split()))
    engine = RoutheEngine(input)
    
    is_stable, table = engine.check_stability()
    print("Stable" if is_stable else "Unstable")
    print("Routhe table:")
    

    for row in table:
        print(row)
    poles = engine.get_poles(input)
    if(poles):
        print("Number of poles: ", len(poles))
        print("Positive Poles: ")
        for pole in poles:
            print(pole)