class SNode<T> {
	public data: T;
	public next: SNode<T> | null;

	constructor(item: T) {
		this.data = item;
		this.next = null;
	}
}

export default class Stack<T> {
	public length: number;
	private top: SNode<T> | undefined;

	constructor() {
		this.top = undefined;
		this.length = 0;
	}

	push(item: T): void {
		const newNode = new SNode(item);

		this.length++;
		if (!this.top) {
			this.top = newNode;
			return;
		}
		newNode.next = this.top;
		this.top = newNode;
	}

	pop(): T | undefined {
		if (!this.top) return undefined;

		this.length--;
		const poppedValue = this.top;

		this.top = this.top.next!;
		return poppedValue.data;
	}

	peek(): T | undefined {
		return this.top?.data;
	}
}
