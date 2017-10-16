TaskController = class("TaskController",BaseController)

function TaskController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TaskController.new(TaskModel:getInstance())
	end 
	return self.instance
end

function TaskController:ctor(model)
	TaskController.super.ctor(self,model)
	
	
	self.model:registerUpdateTaskCBNotify(handler(self,self.UpdateTaskCBNotify))
	self.model:registerAddTaskCBNotify(handler(self,self.AddTaskCBNotify))
	self.model:registerDelTaskCBNotify(handler(self,self.DelTaskCBNotify))

end

function TaskController:modelDataUpdate( syncId, idx )

end





function TaskController:UpdateTaskCBNotify(ret_msg)
end
function TaskController:AddTaskCBNotify(ret_msg)
end
function TaskController:DelTaskCBNotify(ret_msg)
end





