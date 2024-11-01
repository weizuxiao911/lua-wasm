-- 定义一个函数
function greet(name)
    print('Hello, ' .. name .. '!')
end

-- 调用函数
greet('Alice')

-- 条件判断
local age = 25
if age >= 18 then
    print('You are an adult.')
else
    print('You are not an adult.')
end

-- 循环遍历数组
local numbers = {1, 2, 3, 4, 5}
for _, num in ipairs(numbers) do
    print(num)
end

-- 错误处理
local function safe_divide(a, b)
    if b == 0 then
        error('Cannot divide by zero.')
    else
        return a / b
    end
end

local result, err = pcall(safe_divide, 10, 0)
if not result then
    print('Error:', err)
else
    print('Result:', result)
end

-- 定义和调用另一个函数
local function sum(a, b)
    return a + b
end

local total = sum(5, 3)
print('Total:', total)